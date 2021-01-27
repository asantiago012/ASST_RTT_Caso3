 //
 //  Created on: Jan 27, 2021
 //      Author: adri
 //

namespace asst_rtt_caso3;

//
// TODO generated message class
//
packet AsstPacket {
    int 	numHops;
    string 	source;
    double 	sourceTime;
    double 	sinkTime;
    int 	nodes[];
    char 	relleno[]; // 1byte por char
}
