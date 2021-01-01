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

        void putMessageAtEndOfQueue(cMessage *msg);
        int getMessageFromStartOfQueue(cMessage *msg);
        void deleteMessageFromStartOfQueue();

        int sendMessageStopAndWait(cMessage *msg);
        int processMessageStopAndWait(cMessage *msg);
        int sendMessageGoBackN(cMessage *msg);
        int processMessageGoBackN(cMessage *msg);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

        int protocolType;
        float pError;
        vector<cMessage> messageQueue;
};

} /* namespace asst_rtt_caso3 */

#endif /* __ASST_RTT_NETNODE_H_ */
