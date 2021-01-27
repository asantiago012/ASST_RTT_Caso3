/*
 * NetworkDefines.h
 *
 *  Created on: Jan 1, 2021
 *      Author: adri
 */

#ifndef NETWORKDEFINES_H_
#define NETWORKDEFINES_H_


#define PROTOCOLO_TX_NETNODES 0
#define PROBABILIDAD_ERROR_NETNODES 0.05
#define PROBABILIDAD_ROUTE_NETNODES 0.7

#define ACCION_NADA             0
#define ACCION_ENVIAR           1
#define ACCION_ENVIO_OK         2
#define ACCION_ENVIO_NOK        3
#define ACCION_REENVIAR         4
#define ACCION_ENVIAR_Q1        5
#define ACCION_ENVIO_OK_Q1      6
#define ACCION_ENVIO_NOK_Q1     7
#define ACCION_REENVIAR_Q1      8
#define ACCION_ENVIAR_Q2        9
#define ACCION_ENVIO_OK_Q2      10
#define ACCION_ENVIO_NOK_Q2     11
#define ACCION_REENVIAR_Q2      12

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

#define TIEMPO_MEDIO_ENTRE_SERVICIOS 0.333
#define TIEMPO_MEDIO_ENTRE_LLEGADAS  0.5

#define DESCRIPCION_MSG_SERVICETIME "serviceTime"
#define DESCRIPCION_MSG_ARRIVALTIME "arrivalTime"
#define DESCRIPCION_MSG_PACKET      "packet"

#define OUTPUT_GATE_FREE            0
#define OUTPUT_GATE_BUSY            1

#endif /* NETWORKDEFINES_H_ */
