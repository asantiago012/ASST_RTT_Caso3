//
// FullNetNode.ned
//
//  Created on: Jan 1, 2021
//      Author: adri
//

package asst_rtt_caso3;

simple FullNetNode
{
    parameters:
        bool isSource = default(false);
        bool isSink = default(false);
    gates:
        input inBack[];
        input inFordward[];
        output outBack[];
        output outFordward[];
}
