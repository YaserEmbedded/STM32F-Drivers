/*
 * NVIC_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#define NVIC_u8IRQ0 0
#define NVIC_u8IRQ1 1
#define NVIC_u8IRQ2 2
#define NVIC_u8IRQ3 3
#define NVIC_u8IRQ4 4
#define NVIC_u8IRQ5 5
#define NVIC_u8IRQ6 6
#define NVIC_u8IRQ7 7
#define NVIC_u8IRQ8 8
#define NVIC_u8IRQ9 9

#define NVIC_u8IRQ10 10
#define NVIC_u8IRQ11 11
#define NVIC_u8IRQ12 12
#define NVIC_u8IRQ13 13
#define NVIC_u8IRQ14 14
#define NVIC_u8IRQ15 15
#define NVIC_u8IRQ16 16
#define NVIC_u8IRQ17 17
#define NVIC_u8IRQ18 18
#define NVIC_u8IRQ19 19

#define NVIC_u8IRQ20 20
#define NVIC_u8IRQ21 21
#define NVIC_u8IRQ22 22
#define NVIC_u8IRQ23 23
#define NVIC_u8IRQ24 24
#define NVIC_u8IRQ25 25
#define NVIC_u8IRQ26 26
#define NVIC_u8IRQ27 27
#define NVIC_u8IRQ28 28
#define NVIC_u8IRQ29 29

#define NVIC_u8IRQ30 30
#define NVIC_u8IRQ31 31
#define NVIC_u8IRQ32 32
#define NVIC_u8IRQ33 33
#define NVIC_u8IRQ34 34
#define NVIC_u8IRQ35 35
#define NVIC_u8IRQ36 36
#define NVIC_u8IRQ37 37
#define NVIC_u8IRQ38 38
#define NVIC_u8IRQ39 39


#define NVIC_u8IRQ40 40
#define NVIC_u8IRQ41 41
#define NVIC_u8IRQ42 42
#define NVIC_u8IRQ43 43
#define NVIC_u8IRQ44 44
#define NVIC_u8IRQ45 45
#define NVIC_u8IRQ46 46
#define NVIC_u8IRQ47 47
#define NVIC_u8IRQ48 48
#define NVIC_u8IRQ49 49

#define NVIC_u8IRQ50 50
#define NVIC_u8IRQ51 51
#define NVIC_u8IRQ52 52
#define NVIC_u8IRQ53 53
#define NVIC_u8IRQ54 54
#define NVIC_u8IRQ55 55
#define NVIC_u8IRQ56 56
#define NVIC_u8IRQ57 57
#define NVIC_u8IRQ58 58
#define NVIC_u8IRQ59 59

#define NVIC_u8IRQ60 60
#define NVIC_u8IRQ61 61
#define NVIC_u8IRQ62 62
#define NVIC_u8IRQ63 63
#define NVIC_u8IRQ64 64
#define NVIC_u8IRQ65 65
#define NVIC_u8IRQ66 66
#define NVIC_u8IRQ67 67
#define NVIC_u8IRQ68 68
#define NVIC_u8IRQ69 69

#define NVIC_u8IRQ70 70
#define NVIC_u8IRQ71 71
#define NVIC_u8IRQ72 72
#define NVIC_u8IRQ73 73
#define NVIC_u8IRQ74 74
#define NVIC_u8IRQ75 75
#define NVIC_u8IRQ76 76
#define NVIC_u8IRQ77 77
#define NVIC_u8IRQ78 78
#define NVIC_u8IRQ79 79

#define NVIC_u8IRQ80 80
#define NVIC_u8IRQ81 81

/***************************AIRCR Priority levels*******************/
#define PR_LEVELS16  011
#define PR_LEVELS08  100
#define PR_LEVELS04  101
#define PR_LEVELS02  110
#define PR_LEVELS00  111
/*********************************GLOABAL interrupt status**********/
#define ENABLED	 1
#define DISABLED 0
/**************************************APIs*************************/
extern void NVIC_voidInit(void);
extern u8 NVIC_u8EnableIRQ(u8 IRQn);
extern u8 NVIC_u8DisableIRQ(u8 IRQn);
extern u8 NVIC_u8SetPendingIRQ(u8 IRQn);
extern u8 NVIC_u8ClearPendingIRQ(u8 IRQn);
extern u8 NVIC_u8GetPendingIRQ(u8 IRQn,u8 *ptr_IRQstate);
extern void NVIC_voidEnable_Global_IQR(void);
extern void NVIC_voidDisable_Global_IQR(void);
extern u8 NVIC_u8Set_IRQn_Priority(u8 IRQn, u8 copy_u8PRI_level,u8 copy_u8Sub_PRI_level);
extern void SystemResetReq(void);

#endif /* NVIC_INTERFACE_H_ */
