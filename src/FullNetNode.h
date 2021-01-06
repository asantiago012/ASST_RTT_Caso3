/*
 * FullNetNode.h
 *
 *  Created on: Jan 2, 2021
 *      Author: adri
 */

#ifndef FULLNETNODE_H_
#define FULLNETNODE_H_

#include "NetNode.h"

namespace asst_rtt_caso3 {

class FullNetNode: public NetNode {
    public:
        FullNetNode();
        virtual ~FullNetNode();

        int getisSource();
        void setisSource(int is);

        int getisSink();
        void setisSink(int is);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

        int isSource;
        int isSink;

};

} /* namespace asst_rtt_caso3 */

#endif /* FULLNETNODE_H_ */
