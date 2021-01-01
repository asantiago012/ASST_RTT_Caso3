/*
 * NetNode.cc
 *
 *  Created on: Jan 1, 2021
 *      Author: adri
 */

#include "NetNode.h"


namespace asst_rtt_caso3 {

Define_Module(NetNode);

    //////////////////////////////
    // PUBLIC METHODS
    //////////////////////////////
    NetNode::NetNode()
    {
        // TODO Auto-generated constructor stub

    }

    NetNode::~NetNode()
    {
        // TODO Auto-generated destructor stub
    }

    int NetNode::getprotocolType(){
       return protocolType;
    }

    void NetNode::setprotocolType(int protocol){
       protocolType = protocol;
    }

    float NetNode::getpError(){
        return pError;
     }

    void NetNode::setpError(float probability){
        pError = probability;
     }

    float NetNode::getpRoute(){
        return pError;
     }

    void NetNode::setpRoute(float probability){
        pRoute = probability;
     }

    void NetNode::putMessageAtEndOfQueue(cMessage *msg)
    {
        //Introduce mensaje al final de la cola
        messageQueue.push_back(msg);
    }

    int NetNode::getMessageFromStartOfQueue(cMessage *msg)
    {
        //Devuelve 1 y el mensaje, si hay mensaje en la cola
        if (messageQueue.size() > 0)
        {
            msg = messageQueue.at(0);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void NetNode::deleteMessageFromStartOfQueue()
    {
        //Elimina el primer mensaje de la cola
        messageQueue.erase(messageQueue.begin());
    }

    int NetNode::sendMessageNotProtocol(cMessage *msg, int action)
    {
        //Envío de mensajes sin protocolo
        int rc = 0;

        float  probRoute = getpRoute();
        float  probError = getpError();
        float  randomNum = ((float)rand()/RAND_MAX);
        float  randomNumError = ((float)rand()/RAND_MAX);

        if(randomNum < probRoute)
        {
            if(randomNumError < probError)
            {
                (*msg).setKind(MESSAGE_KIND_CORRUPTED);
            }
            send(msg, "out", GATE_INDEX_1);
        }
        else
        {
            if(randomNumError < probError)
            {
                (*msg).setKind(MESSAGE_KIND_CORRUPTED);
            }
            send(msg, "out", GATE_INDEX_2);
        }


        return rc;
    }
    int NetNode::processMessageNotProtocol(cMessage *msg, int *action)
    {
        //Procesamiento de mensajes recibidos sin protocolo
        int rc = 0;

        int messageKind = (*msg).getKind(); //necesario setKind(kindValue) en generacion
        switch(messageKind)
        {
            case MESSAGE_KIND_FROM_SOURCE:
                EV << "Message type: "+to_string((*msg).getKind())+" [src packet] \n";
                break;
            case MESSAGE_KIND_ACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [ACK] \n";
                break;
            case MESSAGE_KIND_NACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [NACK] \n";
                break;
            case MESSAGE_KIND_PACKET:
                EV << "Message type: "+to_string((*msg).getKind())+" [fwd packet] \n";
                break;
            case MESSAGE_KIND_CORRUPTED:
                EV << "Message type: "+to_string((*msg).getKind())+" [err packet] \n";
                break;
            default:
                EV << "Message type: "+to_string((*msg).getKind())+" [default] \n";
                break;
        }


        return rc;
    }

    int NetNode::sendMessageStopAndWait(cMessage *msg, int action)
    {
        //Envío de mensajes con protocolo S&W
        int rc = 0;


        return rc;
    }
    int NetNode::processMessageStopAndWait(cMessage *msg, int *action)
    {
        //Procesamiento de mensajes recibidos con protocolo S&W
        int rc = 0;

        int messageKind = (*msg).getKind(); //necesario setKind(kindValue) en generacion
        switch(messageKind)
        {
            case MESSAGE_KIND_FROM_SOURCE:
                EV << "Message type: "+to_string((*msg).getKind())+" [src packet] \n";
                break;
            case MESSAGE_KIND_ACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [ACK] \n";
                break;
            case MESSAGE_KIND_NACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [NACK] \n";
                break;
            case MESSAGE_KIND_PACKET:
                EV << "Message type: "+to_string((*msg).getKind())+" [fwd packet] \n";
                break;
            case MESSAGE_KIND_CORRUPTED:
                EV << "Message type: "+to_string((*msg).getKind())+" [err packet] \n";
                break;
            default:
                EV << "Message type: "+to_string((*msg).getKind())+" [default] \n";
                break;
        }

        return rc;
    }

    int NetNode::sendMessageGoBackN(cMessage *msg, int action)
    {
        //Envío de mensajes con protocolo GBN
        int rc = 0;


        return rc;
    }
    int NetNode::processMessageGoBackN(cMessage *msg, int *action)
    {
        //Procesamiento de mensajes recibidos con protocolo GBN
        int rc = 0;

        int messageKind = (*msg).getKind(); //necesario setKind(kindValue) en generacion
        switch(messageKind)
        {
            case MESSAGE_KIND_FROM_SOURCE:
                EV << "Message type: "+to_string((*msg).getKind())+" [src packet] \n";
                break;
            case MESSAGE_KIND_ACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [ACK] \n";
                break;
            case MESSAGE_KIND_NACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [NACK] \n";
                break;
            case MESSAGE_KIND_PACKET:
                EV << "Message type: "+to_string((*msg).getKind())+" [fwd packet] \n";
                break;
            case MESSAGE_KIND_CORRUPTED:
                EV << "Message type: "+to_string((*msg).getKind())+" [err packet] \n";
                break;
            default:
                EV << "Message type: "+to_string((*msg).getKind())+" [default] \n";
                break;
        }

        return rc;
    }

    int NetNode::sendMessage(cMessage *msg, int protocolType, int action)
    {
        //Envío de mensajes
        int rc = 0;

        switch(protocolType)
        {
            case PROTOCOLO_TX_STOP_AND_WAIT:
                rc = sendMessageStopAndWait(msg, action);
                if(rc != 0)
                {
                    EV << "ERROR: sendMessageStopAndWait() \n";
                    return;
                }
                break;
            case  PROTOCOLO_TX_GO_BACK_N:
               rc = sendMessageGoBackN(msg, action);
               if(rc != 0)
               {
                   EV << "ERROR: sendMessageGoBackN() \n";
                   return;
               }
                break;
            case PROTOCOLO_TX_NOT_PROTOCOL:
            default:
               rc = sendMessageNotProtocol(msg, action);
               if(rc != 0)
               {
                   EV << "ERROR: sendMessageNotProtocol() \n";
                   return;
               }
                break;
        }

        return rc;
    }
    int NetNode::processMessage(cMessage *msg, int protocolType, int *action)
    {
        //Procesamiento de mensajes recibidos
        int rc = 0;
        (*action) = ACCION_NADA;

        switch(protocolType)
        {
            case PROTOCOLO_TX_STOP_AND_WAIT:
                rc = processMessageStopAndWait(msg, action);
                if(rc != 0)
                {
                    EV << "ERROR: processMessageStopAndWait() \n";
                    return rc;
                }
                break;
            case  PROTOCOLO_TX_GO_BACK_N:
               rc = processMessageGoBackN(msg, action);
               if(rc != 0)
               {
                   EV << "ERROR: processMessageGoBackN() \n";
                   return rc;
               }
                break;
            case PROTOCOLO_TX_NOT_PROTOCOL:
            default:
               rc = processMessageNotProtocol(msg, action);
               if(rc != 0)
               {
                   EV << "ERROR: processMessageNotProtocol() \n";
                   return rc;
               }
                break;
        }

        return rc;
    }

    //////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////
    void NetNode::initialize()
    {

        //PENDIENTE: SWITCH-CASE con parametros de simulacion para seleccionar DEFINES

        setprotocolType(PROTOCOLO_TX_NOT_PROTOCOL);
        setpError(PROBABILIDAD_ERROR_NETNODES);

//        if (par("sendInitialMessage").boolValue())
//        {
//            cMessage *msg = new cMessage("tictocMsg");
//            send(msg, "out");
//        }
    }

    void NetNode::handleMessage(cMessage *msg)
    {
        //Get message properties
        int rc = 0;
        cGate *inputGate = (*msg).getArrivalGate();
        int inputGateIndex = (*inputGate).getIndex();

        int protocolType = getprotocolType();
        int action = ACCION_NADA;

        EV << "Message received from gate: "+to_string(inputGateIndex)+"\n";

        if((*msg).isSelfMessage())
        {
            //Mensajes propios
            EV << "Message type: self-message \n";

            //Comprobar si hay conflicto entre SelfMessage y FromSource cuando Sea SrcNetNode

            //Ejemplo: timers
            //action = ACCION_REENVIAR;
        }
        else
        {
            //Mensajes ajenos
            rc = processMessage(msg, protocolType, &action);
            if(rc != 0)
            {
                EV << "ERROR: processMessage() \n";
                return;
            }

            switch(action)
            {
                case ACCION_ENVIAR:
                    rc = sendMessage(msg, protocolType, action);
                    if(rc != 0)
                    {
                        EV << "ERROR: sendMessage() \n";
                        return;
                    }
                    break;
                case ACCION_ENVIO_OK:
                    deleteMessageFromStartOfQueue();
                    break;
                case ACCION_ENVIO_NOK:
                case ACCION_REENVIAR:
                    rc = sendMessage(msg, protocolType, action);
                    if(rc != 0)
                    {
                        EV << "ERROR: sendMessage() \n";
                        return;
                    }
                    break;
                case ACCION_NADA:
                default:
                    break;
            }


        }

        // just send back the message we received
        send(msg, "out");
    }



} /* namespace asst_rtt_caso3 */
