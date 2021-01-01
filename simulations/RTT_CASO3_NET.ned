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
        tic: NetNode;
        toc: NetNode {
            @display("p=121,61");
        }
    connections:
        tic.out++ --> {  delay = 100ms; } --> toc.in++;
        tic.in++ <-- {  delay = 100ms; } <-- toc.out++;
}
