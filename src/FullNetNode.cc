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
        NetNode::initialize();

        if (par("isSource").boolValue())
        {
            cMessage *msg = new cMessage(DESCRIPCION_MSG_ARRIVALTIME);
            scheduleAt(simTime() + exponential(TIEMPO_MEDIO_ENTRE_LLEGADAS), msg);
            setisSource(1);
        }

        if (par("isSink").boolValue())
        {
            setisSink(1);
        }

        if (par("lambda_mean").doubleValue())
        {
            setisSink(1);
        }

        //mu_mean
    }

    void FullNetNode::handleMessage(cMessage *msg)
    {
        string messageInfo = (*msg).getFullName();
        if(getisSource() && (*msg).isSelfMessage() && messageInfo.compare(DESCRIPCION_MSG_ARRIVALTIME)==0)
        {
            //Si es fuente y es automensaje sin ser tiempo de servicio
            // ... es una "llegada" generada a tx.

            cMessage *msg_packet = new cMessage(DESCRIPCION_MSG_PACKET);
            putMessageAtEndOfQueue(msg_packet);

            scheduleAt(simTime() + exponential(TIEMPO_MEDIO_ENTRE_LLEGADAS), msg); //siguiente llegada
        }
        else if(getisSink() && (*msg).isSelfMessage()==false)
        {
            //Si es sumidero y no es automensaje
            // ... es una "llegada" a morir en este nodo

            //Get message properties
            cGate *inputGate = (*msg).getArrivalGate();
            int inputGateIndex = (*inputGate).getIndex();

        }
        else
        {
            NetNode::handleMessage(msg);
        }

    }
} /* namespace asst_rtt_caso3 */
