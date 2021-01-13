/*
 * FullNetNode.cc
 *
 *  Created on: Jan 2, 2021
 *      Author: adri
 */
#include "FullNetNode.h"

namespace asst_rtt_caso3 {

Define_Module(FullNetNode);

    //////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////
    FullNetNode::FullNetNode() {
        // TODO Auto-generated constructor stub

    }

    FullNetNode::~FullNetNode() {
        // TODO Auto-generated destructor stub
    }

    int FullNetNode::getisSource(){
       return isSource;
    }

    void FullNetNode::setisSource(int is){
        isSource = is;
    }

    int FullNetNode::getisSink(){
       return isSink;
    }

    void FullNetNode::setisSink(int is){
        isSink = is;
    }


    //////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////
    void FullNetNode::initialize()
    {
        //Inicializacion de nodo por defecto
        NetNode::initialize();

        //Inicializacion de tasas de llegadas y servicios
        if (par("lambda_mean").doubleValue())
        {
            setTiempoMedioEntreLlegadas(par("lambda_mean").doubleValue());
        }
        else
        {
            setTiempoMedioEntreLlegadas(TIEMPO_MEDIO_ENTRE_LLEGADAS);
        }
        if (par("mu_mean").doubleValue())
        {
            setTiempoMedioEntreServicios(par("mu_mean").doubleValue());
        }
        else
        {
            setTiempoMedioEntreServicios(TIEMPO_MEDIO_ENTRE_SERVICIOS);
        }


        //Inicializacion de tipo de nodo: Fuente, Sumidero, Ambas o Ninguna
        if (par("isSource").boolValue())
        {
            cMessage *msg_arrival = new cMessage(DESCRIPCION_MSG_ARRIVALTIME);
            scheduleAt(simTime() + exponential(getTiempoMedioEntreLlegadas()), msg_arrival);
            setisSource(1);
        }
        if (par("isSink").boolValue())
        {
            setisSink(1);
        }

        //Inicializacion de parametros de nodo
        if(par("protocol").intValue())
        {
            setprotocolType(par("protocol").intValue());
        }
        if (par("probRutado").doubleValue())
        {
            setpRoute(par("probRutado").doubleValue());
        }

    }

    void FullNetNode::handleMessage(cMessage *msg)
    {
        string messageInfo = (*msg).getFullName();
        if(getisSource() && (*msg).isSelfMessage() && messageInfo.compare(DESCRIPCION_MSG_ARRIVALTIME)==0)
        {
            //Si es fuente y es automensaje sin ser tiempo de servicio
            // ... es una "llegada" generada a tx.

            cMessage *msg_packet = new cMessage(DESCRIPCION_MSG_PACKET);
            (*msg_packet).setKind(MESSAGE_KIND_FROM_SOURCE);
            putMessageAtEndOfQueue(msg_packet);

            cMessage *msg_arrival = new cMessage(DESCRIPCION_MSG_ARRIVALTIME);
            scheduleAt(simTime() + exponential(getTiempoMedioEntreLlegadas()), msg_arrival); //siguiente llegada
        }
        else if(getisSink() && (*msg).isSelfMessage()==false)
        {
            //Si es sumidero y no es automensaje
            // ... es una "llegada" a morir en este nodo

            //Get message properties
            cGate *inputGate = (*msg).getArrivalGate();
            int inputGateIndex = (*inputGate).getIndex();

            /////////////////////////////////////////////////////////
            //Procesamiento de datos de paquete en sumidero destino
            //  exportacion final...

        }
        else
        {
            NetNode::handleMessage(msg);
        }

    }



} /* namespace asst_rtt_caso3 */
