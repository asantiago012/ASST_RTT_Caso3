/*
 * Netnode.h
 *
 *  Created on: Jan 1, 2021
 *      Author: adri
 */

#ifndef __ASST_RTT_NETNODE_H_
#define __ASST_RTT_NETNODE_H_

#include <omnetpp.h>
#include "NetworkDefines.h"
#include <stdio.h>
#include <string.h>

using namespace omnetpp;
using namespace std;

namespace asst_rtt_caso3 {

class NetNode: public cSimpleModule {
    public:
        NetNode();
        virtual ~NetNode();

        int getprotocolType();
        void setprotocolType(int protocol);

        float getpError();
        void setpError(float probability);

        float getpRoute();
        void setpRoute(float probability);

//        int getindexLastGateTx();
//        void setindexLastGateTx(int index);

        int getOutBack1Busy();
        void setOutBack1Busy(int outBack1Busy);
        int getOutBack2Busy();
        void setOutBack2Busy(int outBack2Busy);
        int getOutFordward1Busy() ;
        void setOutFordward1Busy(int outFordward1Busy);
        int getOutFordward2Busy();
        void setOutFordward2Busy(int outFordward2Busy);

        void putMessageAtEndOfQueue(cMessage *msg);
        int getMessageFromStartOfQueue(int queue, cMessage *msg);
        void deleteMessageFromStartOfQueue(int queue);

        int sendMessageNotProtocol(int action);
        int processMessageNotProtocol(cMessage *msg, int *action);
        int sendMessageStopAndWait(int action);
        int processMessageStopAndWait(cMessage *msg, int *action);
        int sendMessageGoBackN(int action);
        int processMessageGoBackN(cMessage *msg, int *action);

        int sendMessage(int protocolType, int action);
        int processMessage(cMessage *msg, int protocolType, int *action);

        float getTiempoMedioEntreLlegadas();
        void setTiempoMedioEntreLlegadas(float tiempoMedioEntreLlegadas);
        float getTiempoMedioEntreServicios();
        void setTiempoMedioEntreServicios(float tiempoMedioEntreServicios);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

        int protocolType;   // 0-2
        float pError;       // 0-1
        float pRoute;       // 0-1

        vector<cMessage> messageQueue1;
        vector<cMessage> messageQueue2;

        //int indexLastGateTx;
        //cExponential arrivalTimes;
        //cExponential serviceTimes;

        int outBack1Busy;
        int outBack2Busy;
        int outFordward1Busy;
        int outFordward2Busy;

        float tiempo_medio_entre_llegadas;
        float tiempo_medio_entre_servicios;
};

} /* namespace asst_rtt_caso3 */

#endif /* __ASST_RTT_NETNODE_H_ */
