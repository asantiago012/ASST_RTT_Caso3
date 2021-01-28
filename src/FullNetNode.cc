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
    FullNetNode::FullNetNode() : NetNode()
    {
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
            AsstPacket *msg_arrival = new AsstPacket(DESCRIPCION_MSG_ARRIVALTIME);
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


        //Numero de paquetes a generar
        if(par("numPackets").intValue())
        {
            setNumPacketsToGenerate(par("numPackets").intValue());
        }

    }

    void FullNetNode::handleMessage(cMessage *msg)
    {
        AsstPacket *packet = check_and_cast<AsstPacket *>(msg);

        string messageInfo = (*packet).getFullName();
        if(getisSource() == 1 && (*packet).isSelfMessage() && messageInfo.compare(DESCRIPCION_MSG_ARRIVALTIME)==0)
        {
            //Si es fuente y es automensaje sin ser tiempo de servicio
            // ... es una "llegada" generada a tx.

            int numPacketsRemaining = getNumPacketsToGenerate();

            if(numPacketsRemaining > 0)
            {
                double pckLngt = exponential(TAM_MEDIO_PAQUETES_BITS);
                char pckName[20];
                memset(pckName, 0, 20);
                sprintf(pckName, "%s_from_%s_seq_%d",DESCRIPCION_MSG_PACKET,getName(),numPacketsRemaining);
                //AsstPacket *msg_packet = new AsstPacket(DESCRIPCION_MSG_PACKET);
                AsstPacket *msg_packet = new AsstPacket(pckName);
                (*msg_packet).setKind(MESSAGE_KIND_FROM_SOURCE);
                (*msg_packet).setSourceTime(SIMTIME_DBL(simTime()));
                (*msg_packet).setPcktPath(getName());
                (*msg_packet).setPcktName((const char *)pckName);

                int size1 = sizeof(msg_packet)*8;
                if(size1 < pckLngt)
                {
                    (*msg_packet).addBitLength(pckLngt-size1);
                }
                int size2 = sizeof(msg_packet);



                int queue = 0;
                putMessageAtEndOfQueue(msg_packet, &queue);

                bubble("Generated Packet");

                numPacketsRemaining--;
                setNumPacketsToGenerate(numPacketsRemaining);

                AsstPacket *msg_arrival = new AsstPacket(DESCRIPCION_MSG_ARRIVALTIME);
                scheduleAt(simTime() + exponential(getTiempoMedioEntreLlegadas()), msg_arrival); //siguiente llegada
            }
        }
        else if(getisSink() == 1 && (*packet).isSelfMessage()==false)
        {
            //Si es sumidero y no es automensaje
            // ... es una "llegada" a morir en este nodo
            (*packet).setSinkTime(SIMTIME_DBL(simTime()));
            string pathAux = (*packet).getPcktPath();
            string pathAuxAux = pathAux.append("-");
            pathAuxAux.append(getName());
            (*packet).setPcktPath(pathAuxAux.data());

            //Get message properties
            cGate *inputGate = (*packet).getArrivalGate();
            int inputGateIndex = (*inputGate).getIndex();



            //Solo contesta con ACK o NACK
            AsstPacket *ack1 = new AsstPacket("ACK");
            AsstPacket *ack2 = new AsstPacket("ACK");
            AsstPacket *nack1 = new AsstPacket("NACK");
            AsstPacket *nack2 = new AsstPacket("NACK");

            ack1->setKind(MESSAGE_KIND_ACK);
            ack2->setKind(MESSAGE_KIND_ACK);
            nack1->setKind(MESSAGE_KIND_NACK);
            nack2->setKind(MESSAGE_KIND_NACK);

            int messageKind = (*packet).getKind(); //necesario setKind(kindValue) en generacion
            switch(messageKind)
            {
                case MESSAGE_KIND_PACKET:
                    if(inputGateIndex == GATE_INDEX_1)
                    {
                        send(ack1, "outBack", GATE_INDEX_1);
                    }
                    else
                    {
                        send(ack2, "outBack", GATE_INDEX_2);
                    }
                    EV << "Message type: "+to_string((*packet).getKind())+" [fwd packet] \n";
                    break;
                case MESSAGE_KIND_CORRUPTED:
                    if(inputGateIndex == GATE_INDEX_1)
                    {
                        send(nack1, "outBack", GATE_INDEX_1);
                    }
                    else
                    {
                        send(nack2, "outBack", GATE_INDEX_2);
                    }
                    EV << "Message type: "+to_string((*packet).getKind())+" [err packet] \n";
                    break;
                default:
                    EV << "Message type: "+to_string((*packet).getKind())+" [default] \n";
                    break;
            }

            /////////////////////////////////////////////////////////
            //Procesamiento de datos de paquete en sumidero destino
            //  exportacion final...
            bubble("Packet arrived to Destination");

            double srcT = (*packet).getSourceTime();
            double snkT = (*packet).getSinkTime();
            double timeTravelling = snkT - srcT;
            char charB[100];
            memset(charB, 0 ,100);
            sprintf(charB, "Packet[%s] Path[%s] TotalTime[%0.3lf]\n",(*packet).getPcktName(),(*packet).getPcktPath(), timeTravelling);
            EV << (const char *)charB;
            bubble((const char *)charB);


        }
        else
        {
            NetNode::handleMessage(packet);
        }

    }



} /* namespace asst_rtt_caso3 */
