#include"types.h"
#include"NVIC_interface.h"
#include"NVIC_private.h"

///////////////////GLOBAL ARRAYS OF POINTER TO REGISTERS////////////////////////
static volatile u32* const NVIC_u32InterruptSetEnable[] = { NVIC_u32ISER0,
NVIC_u32ISER1, NVIC_u32ISER2 };

static volatile u32* const NVIC_u32InterruptClearEnable[] = { NVIC_u32ICER0,
NVIC_u32ICER1, NVIC_u32ICER2 };

static volatile u32* const NVIC_u32InterruptSetPending[] = { NVIC_u32ISPR0,
NVIC_u32ISPR1, NVIC_u32ISPR2 };

static volatile u32* const NVIC_u32InterruptClearPending[] = { NVIC_u32ICPR0,
NVIC_u32ICPR1, NVIC_u32ICPR2 };

static volatile u32* const NVIC_u32Interrupt_priority[] = { NVIC_u32IPR0,
		NVIC_u32IPR1, NVIC_u32IPR2, NVIC_u32IPR3,
		NVIC_u32IPR4, NVIC_u32IPR5, NVIC_u32IPR6, NVIC_u32IPR7, NVIC_u32IPR8,
		NVIC_u32IPR9, NVIC_u32IPR10, NVIC_u32IPR11,
		NVIC_u32IPR12, NVIC_u32IPR13, NVIC_u32IPR14, NVIC_u32IPR15,
		NVIC_u32IPR16, NVIC_u32IPR17, NVIC_u32IPR18,
		NVIC_u32IPR19, NVIC_u32IPR20 };
/*****************************static variables to check enabled or disabled********************************/
static u8 NVIC_EnabledStatus = DISABLED;

#if GLOBAL_INTERRUBTS_STATE == ENABLED
NVIC_EnabledStatus = ENABLED;
#endif

/*******************************************************************************
* Function Name  : NVIC_voidInit
* Description    : Initializes Interrupts(clears Interrupts,clears pending,Config(PRI/SUBPRI),clears IPx[7:4])
* Input          : None
* Return         : None
*******************************************************************************/
extern void NVIC_voidInit() {
	u8 local_u8count;
	for (local_u8count = 0; local_u8count <= 2; local_u8count++)
		{*NVIC_u32InterruptClearEnable[local_u8count] = 0xFFFFFFFF;
/*************************clear all pending***********************/
		*NVIC_u32InterruptClearPending[local_u8count] = 0xFFFFFFFF;}
/*************************initialize AIRCR_Val******************************/
	*NVIC_u32AIRCR = AIRCR_VAL;
/********************initialize NVIC_u32Interrupt_priority by zeros in IPR[7:4]*****************/
	for (local_u8count = 0; local_u8count < 20; local_u8count++)
		*NVIC_u32Interrupt_priority[local_u8count] =
				*NVIC_u32Interrupt_priority[local_u8count] & 0xF0F0F0F0;
/********************initialize the first 8bits in NVIC_u32Interrupt_priority[20] by zeros in IPR[80]*****************/
	*NVIC_u32Interrupt_priority[local_u8count] =
			*NVIC_u32Interrupt_priority[local_u8count] & 0xFFFFFFF0;
/**********************************enable all interrupts*****************************/
#if GLOBAL_INTERRUBTS_STATE == ENABLED
	asm("CPSIE i");
#else
	asm("CPSID i");
#endif

}

/*******************************************************************************
* Function Name  : NVIC_EnableIRQ
* Description    : Enables selected IRQ
* Input          : IRQ number
* Return         : Status
*******************************************************************************/

extern u8 NVIC_EnableIRQ(u8 IRQn) {
	u8 Local_returnstatus = u8ERROR;
	if (IRQn < IRQ_u8MAX) {
		SET_BIT(*NVIC_u32InterruptSetEnable[IRQn / 32], IRQn % 32);
		Local_returnstatus = u8OK;
	}
	return Local_returnstatus;
}

/*******************************************************************************
* Function Name  : NVIC_u8DisableIRQ
* Description    : Disables selected IRQ
* Input          : IRQ number
* Return         : Status
*******************************************************************************/
extern u8 NVIC_u8DisableIRQ(u8 IRQn) {
	u8 Local_returnstatus = u8ERROR;
	if (IRQn < IRQ_u8MAX) {
		SET_BIT(*NVIC_u32InterruptClearEnable[IRQn / 32], IRQn % 32);
		Local_returnstatus = u8OK;
	}
	return Local_returnstatus;
}

/*******************************************************************************
* Function Name  : NVIC_u8ClearPendingIRQ
* Description    : removes selected IRQ from pending and must be used at end of ISR
* Input          : IRQ number
* Return         : Status
*******************************************************************************/

extern u8 NVIC_u8ClearPendingIRQ(u8 IRQn) {
	u8 Local_returnstatus = u8ERROR;
	if (IRQn < IRQ_u8MAX) {
		SET_BIT(*NVIC_u32InterruptClearPending[IRQn / 32], IRQn % 32);
		Local_returnstatus = u8OK;
	}
	return Local_returnstatus;
}

/*******************************************************************************
* Function Name  : NVIC_u8SetPendingIRQ
* Description    : Assign selected IRQ to be pending
* Input          : IRQ number
* Return         : Status
*******************************************************************************/
extern u8 NVIC_u8SetPendingIRQ(u8 IRQn) {
	u8 Local_returnstatus = u8ERROR;
	if (IRQn < IRQ_u8MAX) {
		SET_BIT(*NVIC_u32InterruptSetPending[IRQn / 32], IRQn % 32);
		Local_returnstatus = u8OK;
	}
	return Local_returnstatus;
}

/*******************************************************************************
* Function Name  : NVIC_u8GetPendingIRQ
* Description    : Get selected IRQ pending status
* Input          : IRQ number and pointer to the selected IRQ state
* Return         : Status
*******************************************************************************/
extern u8 NVIC_u8GetPendingIRQ(u8 IRQn, u8 *ptr_IRQstate) {
	u8 Local_returnstatus = u8ERROR;
	if (IRQn < IRQ_u8MAX) {
		*ptr_IRQstate = GET_BIT(*NVIC_u32InterruptSetPending[IRQn / 32],
				IRQn % 32);
		Local_returnstatus = u8OK;
	}
	return Local_returnstatus;
}

/*******************************************************************************
* Function Name  : NVIC_voidEnable_Global_IQR
* Description    : Enable global interrupts
* Input          : None
* Return         : None
*******************************************************************************/
extern void NVIC_voidEnable_Global_IQR(void) {
	asm("CPSIE i");
	NVIC_EnabledStatus = ENABLED;
}

/*******************************************************************************
* Function Name  : NVIC_voidDisable_Global_IQR
* Description    : Disable global interrupts
* Input          : None
* Return         : None
*******************************************************************************/
/*comment:this function to Disable interrupt*/
extern void NVIC_voidDisable_Global_IQR(void) {
	asm("CPSID i");
	NVIC_EnabledStatus = DISABLED;
}
/*******************************************************************************
* Function Name  : NVIC_u8IsGloalInterrutsEnabled
* Description    : Checks Global interrupts status
* Input          : None
* Return         : Global interrupt status
*******************************************************************************/
extern u8 NVIC_u8IsGloalInterrutsEnabled()
{
	return NVIC_EnabledStatus;
}

/*******************************************************************************
* Function Name  : NVIC_u8Set_IRQn_Priority
* Description    : Disable global interrupts
* Input          : Selected IRQn,Priority level,Sub priority level
* Return         : status
*******************************************************************************/
extern u8 NVIC_u8Set_IRQn_Priority(u8 IRQn, u8 copy_u8PRI_level,
		u8 copy_u8Sub_PRI_level) {
	u8 PrMaxLevels = 0;
	u8 SubPrMaxLevels = 0;
	u32 MergePriorities = 0;
	u8 Priorityshift = 0;
#if NVIC_PRIORITY_LEVELS   == PR_LEVELS16
	PrMaxLevels = 17;
	SubPrMaxLevels = 1;
	Priorityshift = 0;
#elif NVIC_PRIORITY_LEVELS == PR_LEVELS08
	PrMaxLevels = 9;
	SubPrMaxLevels = 3;
	Priorityshift = 1;
#elif NVIC_PRIORITY_LEVELS == PR_LEVELS04
	PrMaxLevels = 5;
	SubPrMaxLevels = 5;
	Priorityshift = 2;
#elif NVIC_PRIORITY_LEVELS == PR_LEVELS02
	PrMaxLevels = 3;
	SubPrMaxLevels = 9;
	Priorityshift = 3;
#elif NVIC_PRIORITY_LEVELS == PR_LEVELS00
	PrMaxLevels = 1;
	SubPrMaxLevels = 17;
	Priorityshift = 0;
#endif

	u8 local_u8returnstatus = u8ERROR;
	if ((IRQn < IRQ_u8MAX - 1) && copy_u8PRI_level << PrMaxLevels
			&& copy_u8Sub_PRI_level < SubPrMaxLevels) {
		MergePriorities = copy_u8PRI_level << Priorityshift
				| copy_u8Sub_PRI_level;
		/*****************************clear priority section********************************************/
		*NVIC_u32Interrupt_priority[IRQn / 4] = *NVIC_u32Interrupt_priority[IRQn
				/ 4] & (00001111 << ((IRQn % 4) * 8));
		*NVIC_u32Interrupt_priority[IRQn / 4] = *NVIC_u32Interrupt_priority[IRQn
				/ 4] | ((MergePriorities << 4) << ((IRQn % 4) * 8));
		local_u8returnstatus = u8OK;
	}
	return local_u8returnstatus;
}

/*******************************************************************************
* Function Name  : SystemResetReq
* Description    : Restarts the system
* Input          : None
* Return         : None
*******************************************************************************/
extern void SystemResetReq()
{
	*NVIC_u32AIRCR = *NVIC_u32AIRCR | (u32)0x04;
}
