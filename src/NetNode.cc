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

    int NetNode::getindexLastGateTx(){
        return indexLastGateTx;
    }
    void NetNode::setindexLastGateTx(int index){
        indexLastGateTx = index;
    }

    int NetNode::getOutBack1Busy(){
        return outBack1Busy;
    }

    void NetNode::setOutBack1Busy(int isBusy) {
        outBack1Busy = isBusy;
    }

    int NetNode::getOutBack2Busy(){
        return outBack2Busy;
    }

    void NetNode::setOutBack2Busy(int isBusy) {
        outBack2Busy = outBack2Busy;
    }

    int NetNode::getOutFordward1Busy() {
        return outFordward1Busy;
    }

    void NetNode::setOutFordward1Busy(int isBusy) {
        outFordward1Busy = isBusy;
    }

    int NetNode::getOutFordward2Busy(){
        return outFordward2Busy;
    }

    void NetNode::setOutFordward2Busy(int isBusy) {
        outFordward2Busy = isBusy;
    }

    void NetNode::putMessageAtEndOfQueue(cMessage *msg)
    {
        //Introduce mensaje al final de la cola
        messageQueue.push_back(*msg);
    }

    int NetNode::getMessageFromStartOfQueue(cMessage *msg)
    {
        //Devuelve 1 y el mensaje, si hay mensaje en la cola
        if (messageQueue.size() > 0)
        {
            (*msg) = messageQueue.at(0);
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
        if (messageQueue.size() > 0)
        {
            messageQueue.erase(messageQueue.begin());
        }
    }

    int NetNode::sendMessageNotProtocol(int action)
    {
        //Envío de mensajes sin protocolo
        int rc = 0;

        float  probRoute = getpRoute();
        float  probError = getpError();
        float  randomNum = ((float)rand()/RAND_MAX);
        float  randomNumError = ((float)rand()/RAND_MAX);

        cMessage *msg = new cMessage();
        if(getMessageFromStartOfQueue(msg))
        {
            if(getindexLastGateTx() == -1)
            {
                //New packet to send
                if(randomNum < probRoute)
                {
                    if(randomNumError < probError)
                    {
                        (*msg).setKind(MESSAGE_KIND_CORRUPTED);
                    }
                    send(msg, "outFordward", GATE_INDEX_1);
                    setindexLastGateTx(GATE_INDEX_1);
                }
                else
                {
                    if(randomNumError < probError)
                    {
                        (*msg).setKind(MESSAGE_KIND_CORRUPTED);
                    }
                    send(msg, "outFordward", GATE_INDEX_2);
                    setindexLastGateTx(GATE_INDEX_2);
                }
            }
            else
            {
                //Resend packet
                send(msg, "outFordward", getindexLastGateTx());
            }
        }


        return rc;
    }
    int NetNode::processMessageNotProtocol(cMessage *msg, int *action)
    {
        //Procesamiento de mensajes recibidos sin protocolo
        int rc = 0;
        (*action) = ACCION_NADA;

        int messageKind = (*msg).getKind(); //necesario setKind(kindValue) en generacion
        switch(messageKind)
        {
            case MESSAGE_KIND_FROM_SOURCE:
                EV << "Message type: "+to_string((*msg).getKind())+" [src packet] \n";
                (*action) = ACCION_ENVIAR;
                break;
            case MESSAGE_KIND_ACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [ACK] \n";
                (*action) = ACCION_ENVIO_OK;
                break;
            case MESSAGE_KIND_NACK:
                EV << "Message type: "+to_string((*msg).getKind())+" [NACK] \n";
                (*action) = ACCION_ENVIO_NOK;
                break;
            case MESSAGE_KIND_PACKET:
                EV << "Message type: "+to_string((*msg).getKind())+" [fwd packet] \n";
                (*action) = ACCION_ENVIAR;
                break;
            case MESSAGE_KIND_CORRUPTED:
                EV << "Message type: "+to_string((*msg).getKind())+" [err packet] \n";
                (*action) = ACCION_ENVIO_NOK;
                break;
            default:
                EV << "Message type: "+to_string((*msg).getKind())+" [default] \n";
                (*action) = ACCION_ENVIAR;
                break;
        }


        return rc;
    }

    int NetNode::sendMessageStopAndWait(int action)
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

    int NetNode::sendMessageGoBackN(int action)
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

    int NetNode::sendMessage(int protocolType, int action)
    {
        //Envío de mensajes
        int rc = 0;

        switch(protocolType)
        {
            case PROTOCOLO_TX_STOP_AND_WAIT:
                rc = sendMessageStopAndWait(action);
                if(rc != 0)
                {
                    EV << "ERROR: sendMessageStopAndWait() \n";
                    return rc;
                }
                break;
            case  PROTOCOLO_TX_GO_BACK_N:
               rc = sendMessageGoBackN(action);
               if(rc != 0)
               {
                   EV << "ERROR: sendMessageGoBackN() \n";
                   return rc;
               }
                break;
            case PROTOCOLO_TX_NOT_PROTOCOL:
            default:
               rc = sendMessageNotProtocol(action);
               if(rc != 0)
               {
                   EV << "ERROR: sendMessageNotProtocol() \n";
                   return rc;
               }
               deleteMessageFromStartOfQueue();
               setindexLastGateTx(-1);
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
        setpRoute(PROBABILIDAD_ROUTE_NETNODES);
        setindexLastGateTx(-1);

        setOutBack1Busy(OUTPUT_GATE_FREE);
        setOutBack2Busy(OUTPUT_GATE_FREE);
        setOutFordward1Busy(OUTPUT_GATE_FREE);
        setOutFordward2Busy(OUTPUT_GATE_FREE);


        cMessage *msg_service = new cMessage(DESCRIPCION_MSG_SERVICETIME);
        scheduleAt(simTime() + exponential(TIEMPO_MEDIO_ENTRE_SERVICIOS), msg_service);
    }

    void NetNode::handleMessage(cMessage *msg)
    {
        int rc = 0;

        int protocolType = getprotocolType();
        int action = ACCION_NADA;
        if((*msg).isSelfMessage())
        {
            //Mensajes propios
            //Tiempos de servicio
            EV << "Message type: self-message \n";
            action = ACCION_ENVIAR;
            rc = sendMessage(protocolType, action);
            if(rc != 0)
            {
                EV << "ERROR: sendMessage() \n";
                return;
            }

            scheduleAt(simTime() + exponential(TIEMPO_MEDIO_ENTRE_SERVICIOS), msg); //siguiente tiempo de servicio
            //Comprobar si hay conflicto entre SelfMessage y FromSource cuando Sea SrcNetNode

        }
        else
        {
            //Get message properties
            cGate *inputGate = (*msg).getArrivalGate();
            int inputGateIndex = (*inputGate).getIndex();
            EV << "Message received from gate: "+to_string(inputGateIndex)+"\n";

            //Mensajes ajenos
            //Interaccion con otros nodos: poner/quitar cola
            rc = processMessage(msg, protocolType, &action);
            if(rc != 0)
            {
                EV << "ERROR: processMessage() \n";
                return;
            }

            switch(action)
            {
                case ACCION_ENVIAR:
                    putMessageAtEndOfQueue(msg);
                    break;
                case ACCION_ENVIO_OK:
                    deleteMessageFromStartOfQueue();
                    setindexLastGateTx(-1);
                    break;
                case ACCION_ENVIO_NOK:
                case ACCION_REENVIAR:
                case ACCION_NADA:
                default:
                    break;
            }


        }

    }



} /* namespace asst_rtt_caso3 */
