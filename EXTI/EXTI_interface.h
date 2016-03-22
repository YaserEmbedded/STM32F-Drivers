/*
 * EXTI_interface.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Home
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/*****************interrupt detecting edge************************/
#define EXTI_RISINGEDGE  1
#define EXTI_FALLINGEDGE 0
/**********************ENABLE EXTI no***************************/
#define EXTI_ON	  1
#define EXTI_OFF  0

/*****************************************************************/

extern void EXTI_voidInit(void);
extern u8 EXTI_u8IMR(u8 EXTIno, u8 EnableState);
extern u8 EXTI_u8DetectionEdge(u8 EXTIno, u8 EdgeState);
extern u8 EXTI_u8ClearPendingStatus(u8 EXTIno);
extern u8 EXTI_u8ReadPendingStatus(u8 EXTIno, u8 * Pending_u8Status);
#endif /* EXTI_INTERFACE_H_ */
