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

    int NetNode::sendMessageStopAndWait(cMessage *msg)
    {
        //Envío de mensajes con protocolo S&W
        int rc = 1;


        return rc;
    }

    int NetNode::processMessageStopAndWait(cMessage *msg)
    {
        //Procesamiento de mensajes recibidos con protocolo S&W
        int rc = 1;


        return rc;
    }

    int NetNode::sendMessageGoBackN(cMessage *msg)
    {
        //Envío de mensajes con protocolo GBN
        int rc = 1;


        return rc;
    }

    int NetNode::processMessageGoBackN(cMessage *msg)
    {
        //Procesamiento de mensajes recibidos con protocolo GBN
        int rc = 1;


        return rc;
    }

    //////////////////////////////
    // PROTECTED METHODS
    //////////////////////////////
    void NetNode::initialize()
    {
        setprotocolType(PROTOCOLO_TX_NETNODES);
        setpError(PROBABILIDAD_ERROR_NETNODES);

//        if (par("sendInitialMessage").boolValue())
//        {
//            cMessage *msg = new cMessage("tictocMsg");
//            send(msg, "out");
//        }
    }

    void NetNode::handleMessage(cMessage *msg)
    {
        // just send back the message we received
        send(msg, "out");
    }



} /* namespace asst_rtt_caso3 */
