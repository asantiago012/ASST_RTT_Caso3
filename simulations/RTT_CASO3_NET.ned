//
// RTT_CASO3_NET.ned
//
//  Created on: Jan 1, 2021
//      Author: adri
//

package asst_rtt_caso3.simulations;

import asst_rtt_caso3.NetNode;

//
// 
//
network RTT_CASO3_NET
{
    submodules:
        src: NetNode {
            //@display("i=block/source,red");
            @display("i=device/router,red;p=48,130");
        }
        node1: NetNode {
            @display("i=device/router,blue;p=136,62");
        }
        node2: NetNode {
            @display("i=device/router,blue;p=136,222");
        }
    connections:
        src.out++ --> {  delay = 100ms; } --> node1.in++;
        src.in++ <-- {  delay = 100ms; } <-- node1.out++;

        src.out++ --> {  delay = 100ms; } --> node2.in++;
        src.in++ <-- {  delay = 100ms; } <-- node2.out++;
}
