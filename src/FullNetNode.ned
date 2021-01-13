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
        bool   isSource = default(false); 	//indica si es fuente de paquetes (origen)
        double lambda_mean = default(1);	//si es fuente, media de tasa de llegadas
        bool   isSink = default(false);		//indica si es sumidero de paquetes (destino)
        double mu_mean = default(1);		//tasa media de servicios
        int protocol = default(0);			//Tipo protocolo utilizado: none, S&W o GBN
        double probRutado = default(0.5);	//Probabilidad de envio por output 1 del nodo
    gates:
        input  inBack[];
        input  inFordward[];
        output outBack[];
        output outFordward[];
}
