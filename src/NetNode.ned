//
// NetNode.ned
//
//  Created on: Jan 1, 2021
//      Author: adri
//

package asst_rtt_caso3;

simple NetNode
{
    parameters:
        bool sendInitialMessage = default(false);
    gates:
        input in[];
        output out[];
}
