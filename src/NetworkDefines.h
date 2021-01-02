/*
 * NetworkDefines.h
 *
 *  Created on: Jan 1, 2021
 *      Author: adri
 */

#ifndef NETWORKDEFINES_H_
#define NETWORKDEFINES_H_


#define PROTOCOLO_TX_NETNODES 0
#define PROBABILIDAD_ERROR_NETNODES 0.1
#define PROBABILIDAD_ROUTE_NETNODES 0.7

#define ACCION_NADA         0
#define ACCION_ENVIAR       1
#define ACCION_ENVIO_OK     2
#define ACCION_ENVIO_NOK    3
#define ACCION_REENVIAR     4

#define PROTOCOLO_TX_NOT_PROTOCOL   0
#define PROTOCOLO_TX_STOP_AND_WAIT  1
#define PROTOCOLO_TX_GO_BACK_N      2

#define MESSAGE_KIND_FROM_SOURCE    1
#define MESSAGE_KIND_ACK            2
#define MESSAGE_KIND_NACK           3
#define MESSAGE_KIND_PACKET         4
#define MESSAGE_KIND_CORRUPTED      5

#define GATE_INDEX_1    0
#define GATE_INDEX_2    1

#define TIEMPO_ENTRE_SERVICIOS 1
#define TIEMPO_ENTRE_LLEGADAS  1.5

#define DESCRIPCION_MSG_SERVICETIME "serviceTime"
#define DESCRIPCION_MSG_ARRIVALTIME "arrivalTime"
#define DESCRIPCION_MSG_PACKET      "packet"


#endif /* NETWORKDEFINES_H_ */
