//
// RTT_CASO3_NET.ned
//
//  Created on: Jan 1, 2021
//      Author: adri
//

package asst_rtt_caso3.simulations;

//import asst_rtt_caso3.NetNode;
import asst_rtt_caso3.FullNetNode;

//
// 
//
network RTT_CASO3_NET
{
    submodules:
        src1: FullNetNode {
            //@display("i=block/source,red");
            @display("i=device/router,red;p=50,130");
            @display("t=Queue1: 0\nQueue2: 0\nBusyQueue1: 0\nBusyQueue2: 0;tt= Node1(Source)");
        }
        src2: FullNetNode {
            @display("i=device/router,red;p=200,62");
            @display("t=Queue1: 0\nQueue2: 0\nBusyQueue1: 0\nBusyQueue2: 0;tt=Node2(Source)");
        }
        src5: FullNetNode {
            @display("i=device/router,red;p=200,222");
            @display("t=Queue1: 0\nQueue2: 0\nBusyQueue1: 0\nBusyQueue2: 0;tt=Node5(Source)");
        }
        snk3: FullNetNode {
            @display("i=device/router,blue;p=350,62");
            @display("tt=Node3(Sink)");
            //@display("t=Queue1: 0\nQueue2: 0;tt=Node3(Sink)");
        }
        snk4: FullNetNode {
            @display("i=device/router,blue;p=350,222");
            @display("tt=Node4(Sink)");
            //@display("t=Queue1: 0\nQueue2: 0;tt=Node4(Sink)");
        }
    connections:
        //CX: 1-2
        src1.outFordward++ --> {  delay = 100ms; } --> src2.inBack++;
        src1.inFordward++ <-- {  delay = 100ms; } <-- src2.outBack++;
        
        //CX: 1-5
        src1.outFordward++ --> {  delay = 100ms; } --> src5.inBack++;
        src1.inFordward++ <-- {  delay = 100ms; } <-- src5.outBack++;
        
        //CX: 2-3
        src2.outFordward++ --> {  delay = 100ms; } --> snk3.inBack++;
        src2.inFordward++ <-- {  delay = 100ms; } <-- snk3.outBack++;
        
        //CX: 2-4
        src2.outFordward++ --> {  delay = 100ms; } --> snk4.inBack++;
        src2.inFordward++ <-- {  delay = 100ms; } <-- snk4.outBack++;

      	//CX: 5-2
        src5.outFordward++ --> {  delay = 100ms; } --> src2.inBack++;
        src5.inFordward++ <-- {  delay = 100ms; } <-- src2.outBack++;
        
        //CX: 5-4
        src5.outFordward++ --> {  delay = 100ms; } --> snk4.inBack++;
        src5.inFordward++ <-- {  delay = 100ms; } <-- snk4.outBack++;
        
        //CX: aux 3-4 (para pruebas y que no casque)
//        snk3.outFordward++ --> {  delay = 100ms; } --> snk4.inBack++;
//        snk3.inFordward++ <-- {  delay = 100ms; } <-- snk4.outBack++;
//        snk3.outFordward++ --> {  delay = 100ms; } --> snk4.inBack++;
//        snk3.inFordward++ <-- {  delay = 100ms; } <-- snk4.outBack++;
//        snk4.outFordward++ --> {  delay = 100ms; } --> snk3.inBack++;
//        snk4.inFordward++ <-- {  delay = 100ms; } <-- snk3.outBack++;
//        snk4.outFordward++ --> {  delay = 100ms; } --> snk3.inBack++;
//        snk4.inFordward++ <-- {  delay = 100ms; } <-- snk3.outBack++;
}
