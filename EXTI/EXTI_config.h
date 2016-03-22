/*
 * EXTI_config.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Home
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/**********************ENABLE EXTI no***************************/
#define EXTI_0_STATE		EXTI_ON /*EXTI_ON or EXTI_OFF*/
#define EXTI_1_STATE		EXTI_ON
#define EXTI_2_STATE		EXTI_ON
#define EXTI_3_STATE		EXTI_ON
#define EXTI_4_STATE		EXTI_ON
#define EXTI_5_STATE		EXTI_ON
#define EXTI_6_STATE		EXTI_ON
#define EXTI_7_STATE		EXTI_ON
#define EXTI_8_STATE		EXTI_ON
#define EXTI_9_STATE		EXTI_ON
#define EXTI_10_STATE		EXTI_ON
#define EXTI_11_STATE		EXTI_ON
#define EXTI_12_STATE		EXTI_ON
#define EXTI_13_STATE		EXTI_ON
#define EXTI_14_STATE		EXTI_ON
#define EXTI_15_STATE		EXTI_ON
#define EXTI_16_STATE		EXTI_OFF
#define EXTI_17_STATE		EXTI_OFF
#define EXTI_18_STATE		EXTI_OFF
#define EXTI_19_STATE		EXTI_OFF
#define EXTI_20_STATE		EXTI_OFF
#define EXTI_21_STATE		EXTI_OFF
#define EXTI_22_STATE		EXTI_OFF
#define EXTI_23_STATE		EXTI_OFF

/**********************EXTI PIN***************************/
#define EXTI_0_PIN	//holds from GPIO_u8PIN1 - GPIO_u8PIN16
#define EXTI_1_PIN
#define EXTI_2_PIN
#define EXTI_3_PIN
#define EXTI_4_PIN
#define EXTI_5_PIN
#define EXTI_6_PIN
#define EXTI_7_PIN
#define EXTI_8_PIN
#define EXTI_9_PIN
#define EXTI_10_PIN
#define EXTI_11_PIN
#define EXTI_12_PIN
#define EXTI_13_PIN
#define EXTI_14_PIN
#define EXTI_15_PIN
/**********************Special EXTI PIN***************************/
#define EXTI_16_PIN
#define EXTI_17_PIN
#define EXTI_18_PIN
#define EXTI_19_PIN
#define EXTI_20_PIN
#define EXTI_21_PIN
#define EXTI_22_PIN
/**********************EXTI Port***************************/
#define EXTI_0_PORT	//holds from GIO_u8PORTA - GIO_u8PORTH
#define EXTI_1_PORT
#define EXTI_2_PORT
#define EXTI_3_PORT
#define EXTI_4_PORT
#define EXTI_5_PORT
#define EXTI_6_PORT
#define EXTI_7_PORT
#define EXTI_8_PORT
#define EXTI_9_PORT
#define EXTI_10_PORT
#define EXTI_11_PORT
#define EXTI_12_PORT										/*cannot use port I*/
#define EXTI_13_PORT										/*cannot use port I*/
#define EXTI_14_PORT										/*cannot use port I*/
#define EXTI_15_PORT										/*cannot use port I*/
/**********************Special EXTI port***************************/
#define EXTI_16_PORT
#define EXTI_17_PORT
#define EXTI_18_PORT
#define EXTI_19_PORT
#define EXTI_20_PORT
#define EXTI_21_PORT
#define EXTI_22_PORT
/**********************EXtI rising/falling/both**************/
#define EXTI_0_EDGE
#define EXTI_1_EDGE
#define EXTI_2_EDGE
#define EXTI_3_EDGE
#define EXTI_4_EDGE
#define EXTI_5_EDGE
#define EXTI_6_EDGE
#define EXTI_7_EDGE
#define EXTI_8_EDGE
#define EXTI_9_EDGE
#define EXTI_10_EDGE
#define EXTI_11_EDGE
#define EXTI_12_EDGE
#define EXTI_13_EDGE
#define EXTI_14_EDGE
#define EXTI_15_EDGE
/**********************Special EXTI rising/falling/both***************************/
#define EXTI_16_EDGE
#define EXTI_17_EDGE
#define EXTI_18_EDGE
#define EXTI_19_EDGE
#define EXTI_20_EDGE
#define EXTI_21_EDGE
#define EXTI_22_EDGE

#endif /* EXTI_CONFIG_H_ */
