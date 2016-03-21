/*
 * NVIC_private.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*comment: interrupt service enable register*/
#define NVIC_u32ISER0 ((volatile u32*)(0xE000E100))
#define NVIC_u32ISER1 ((volatile u32*)(0xE000E104))
#define NVIC_u32ISER2 ((volatile u32*)(0xE000E108))

/*comment: interrupt clear enable register*/
#define NVIC_u32ICER0 ((volatile u32*)(0xE000E180))
#define NVIC_u32ICER1 ((volatile u32*)(0xE000E184))
#define NVIC_u32ICER2 ((volatile u32*)(0xE000E188))

/*comment: interrupt set pending register*/
#define NVIC_u32ISPR0 ((volatile u32*)(0xE000E200))
#define NVIC_u32ISPR1 ((volatile u32*)(0xE000E204))
#define NVIC_u32ISPR2 ((volatile u32*)(0xE000E208))


/*comment: interrupt clear pending register*/
#define NVIC_u32ICPR0 ((volatile u32*)(0xE000E280))
#define NVIC_u32ICPR1 ((volatile u32*)(0xE000E284))
#define NVIC_u32ICPR2 ((volatile u32*)(0xE000E288))
/********************AIRCR_Address*************************************/
#define NVIC_u32AIRCR ((volatile u32*)(0xE000ED0C))
/********************IPR  Addresses************************************/
#define NVIC_u32IPR0  ((volatile u32*)(0xE000E400))
#define NVIC_u32IPR1  ((volatile u32*)(0xE000E404))
#define NVIC_u32IPR2  ((volatile u32*)(0xE000E408))
#define NVIC_u32IPR3  ((volatile u32*)(0xE000E40C))
#define NVIC_u32IPR4  ((volatile u32*)(0xE000E410))
#define NVIC_u32IPR5  ((volatile u32*)(0xE000E414))
#define NVIC_u32IPR6  ((volatile u32*)(0xE000E418))
#define NVIC_u32IPR7  ((volatile u32*)(0xE000E41C))
#define NVIC_u32IPR8  ((volatile u32*)(0xE000E420))
#define NVIC_u32IPR9  ((volatile u32*)(0xE000E424))
#define NVIC_u32IPR10 ((volatile u32*)(0xE000E428))
#define NVIC_u32IPR11 ((volatile u32*)(0xE000E42C))
#define NVIC_u32IPR12 ((volatile u32*)(0xE000E430))
#define NVIC_u32IPR13 ((volatile u32*)(0xE000E434))
#define NVIC_u32IPR14 ((volatile u32*)(0xE000E438))
#define NVIC_u32IPR15 ((volatile u32*)(0xE000E43C))
#define NVIC_u32IPR16 ((volatile u32*)(0xE000E440))
#define NVIC_u32IPR17 ((volatile u32*)(0xE000E444))
#define NVIC_u32IPR18 ((volatile u32*)(0xE000E448))
#define NVIC_u32IPR19 ((volatile u32*)(0xE000E44C))
#define NVIC_u32IPR20 ((volatile u32*)(0xE000E450))
/******************************priority max check********************/
//#if NVIC_PRIORITY_LEVELS  PR_LEVELS16
//#define PrMaxLevels  17
//#elif NVIC_PRIORITY_LEVELS == PR_LEVELS08
//#define PrMaxLevels   9
//#elif NVIC_PRIORITY_LEVELS == PR_LEVELS04
//#define PrMaxLevels   5
//#elif NVIC_PRIORITY_LEVELS == PR_LEVELS00
//#define PrMaxLevels   1
//#endif

/*comment:	Concatinate AIRCR initial value*/
#define AIRCR_WRITE_CONDITION  		0101111110100000
#define AIRCR_ENDIANESS_RESERVERED  00000
#define AIRCR_LASTBYTE				00000000

#define AIRCR_VAL  CONC(AIRCR_WRITE_CONDITION,00000,PR_LEVELS16,00000000)
#define CONC(AIRCR_WRITE_CONDITION,AIRCR_ENDIANESS_RESERVERED,NVIC_PRIORITY_LEVELS,AIRCR_LASTBYTE)		CONC_HELP(AIRCR_WRITE_CONDITION,AIRCR_ENDIANESS_RESERVERED,NVIC_PRIORITY_LEVELS,AIRCR_LASTBYTE)
#define CONC_HELP(AIRCR_WRITE_CONDITION,AIRCR_ENDIANESS_RESERVERED,NVIC_PRIORITY_LEVELS,AIRCR_LASTBYTE)	0b##AIRCR_WRITE_CONDITION##AIRCR_ENDIANESS_RESERVERED##NVIC_PRIORITY_LEVELS##AIRCR_LASTBYTE
#define IRQ_u8MAX 82
#endif /* NVIC_PRIVATE_H_ */
