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

        int getindexLastGateTx();
        void setindexLastGateTx(int index);

        void putMessageAtEndOfQueue(cMessage *msg);
        int getMessageFromStartOfQueue(cMessage *msg);
        void deleteMessageFromStartOfQueue();

        int sendMessageNotProtocol(int action);
        int processMessageNotProtocol(cMessage *msg, int *action);
        int sendMessageStopAndWait(int action);
        int processMessageStopAndWait(cMessage *msg, int *action);
        int sendMessageGoBackN(int action);
        int processMessageGoBackN(cMessage *msg, int *action);

        int sendMessage(int protocolType, int action);
        int processMessage(cMessage *msg, int protocolType, int *action);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

        int protocolType;   // 0-2
        float pError;       // 0-1
        float pRoute;       // 0-1
        vector<cMessage> messageQueue;
        int indexLastGateTx;
        cExponential arrivalTimes;
        cExponential serviceTimes;
};

} /* namespace asst_rtt_caso3 */

#endif /* __ASST_RTT_NETNODE_H_ */
