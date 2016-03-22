/*
 * EXTI_prog.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Home
 */

#include "types.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/*****************************static variables to keep track of EXTI ON and OFF********************************/
static u32  EXTI_u32state = 0;
/*******************************************************************************
* Function Name  : EXTI_voidInit
* Description    : Initializes EXT-Interrupts SYSCONFIG,EXT-Interrupts EXTI_IMR,EXT-Interrupts EXTI_u32RTSR and EXT-Interrupts EXTI_u32FTSR
* Input          : None
* Return         : None
*******************************************************************************/
extern void EXTI_voidInit()
{u8 local_u8count;
	/************ANWAAAAAAAAAAAAAAAAR System config************************/
	/*******************choose which pin on which port to be enabled******/


	/**************************EXTI_IMR initialization********************/
	for(local_u8count = 0;local_u8count<23;local_u8count++)
	{	switch(GET_BIT(EXTIx_STATE,local_u8count))
		{
		case EXTI_ON:
			SET_BIT(EXTI_u32IMR,local_u8count);
			SET_BIT(EXTI_u32state,local_u8count);
			break;
		case EXTI_OFF:
			CLR_BIT(EXTI_u32IMR,local_u8count);
			CLR_BIT(EXTI_u32state,local_u8count);
			break;
		default:
			break;
		}
	}
	/**************************EXTI_u32RTSR and EXTI_u32FTSR initialization********************/
	for(local_u8count = 0;local_u8count<23;local_u8count++)
		{	switch(GET_BIT(EXTIx_EGDEDETECT,local_u8count))
			{
			case EXTI_ON:
				SET_BIT(EXTI_u32RTSR,local_u8count);
				break;
			case EXTI_OFF:
				SET_BIT(EXTI_u32FTSR,local_u8count);
				break;
			default:
				break;
			}
		}

}
/*******************************************************************************
* Function Name  : EXTI_u8IMR
* Description    : Enables/Disable
* Input          : EXTI number, Desired EnableState
* Return         : operation status
*******************************************************************************/

extern u8 EXTI_u8IMR(u8 EXTIno, u8 EnableState)
{u8 local_returnStatus = u8ERROR;

	switch(EnableState)
			{
			case EXTI_ON:
				SET_BIT(EXTI_u32IMR,EXTIno);local_returnStatus = u8OK;
				break;
			case EXTI_OFF:
				CLR_BIT(EXTI_u32IMR,EXTIno);local_returnStatus = u8OK;
				break;
			default:local_returnStatus = u8ERROR;
				break;
			}
	return local_returnStatus;
}
/*******************************************************************************
* Function Name  : EXTI_u8DetectionEdge
* Description    : set Detection state Desired
* Input          : EXTI number, Detection state Desired
* Return         : operation status
*******************************************************************************/
extern u8 EXTI_u8DetectionEdge(u8 EXTIno, u8 EdgeState)
{u8 local_returnStatus = u8ERROR;

if(GET_BIT(EXTI_u32state,EXTIno) != EXTI_OFF)
	switch (EdgeState) {
	case EXTI_RISINGEDGE:
		SET_BIT(EXTI_u32RTSR, EXTIno);local_returnStatus = u8OK;
		break;
	case EXTI_FALLINGEDGE:
		SET_BIT(EXTI_u32FTSR, EXTIno);local_returnStatus = u8OK;
		break;
	default:local_returnStatus = u8ERROR;
		break;
	}
	return local_returnStatus;
}

/*******************************************************************************
* Function Name  : EXTI_u8ClearPendingStatus
* Description    : clear Pending state MUST AFTER EXECUTION
* Input          : EXTI number
* Return         : operation status
*******************************************************************************/
extern u8 EXTI_u8ClearPendingStatus(u8 EXTIno)
{
	u8 local_returnStatus = u8ERROR;

	if(EXTIno < 23  && GET_BIT(EXTI_u32state,EXTIno) != EXTI_OFF)
	{
		CLR_BIT(*EXTI_u32PR,EXTIno);
		local_returnStatus = u8OK;
	}
return local_returnStatus;
}

/*******************************************************************************
* Function Name  : EXTI_u8ClearPendingStatus
* Description    : reads Pending state
* Input          : EXTI number and pointer to Pending state
* Return         : operation status
*******************************************************************************/

extern u8 EXTI_u8ReadPendingStatus(u8 EXTIno, u8 * Pending_u8Status)
{
	u8 local_returnStatus = u8ERROR;

	if(EXTIno < 23  && GET_BIT(EXTI_u32state,EXTIno) != EXTI_OFF)
	{
		* Pending_u8Status = GET_BIT(*EXTI_u32PR,EXTIno);
		local_returnStatus = u8OK;
	}
	return local_returnStatus;
}
