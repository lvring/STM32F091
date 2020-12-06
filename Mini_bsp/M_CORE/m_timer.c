#include "m_timer.h"
#include "m_scheduler.h"


/*************************************************
*** Args:   Delay
					Null
*** Function: —” ±“ª∂Œ∫¡√Î
*************************************************/
void M_DelayMS(uint32_t Delay) {
	/* Delay for amount of milliseconds */
	/* Check if we are called from ISR */
	if (__get_IPSR() == 0) {
		/* Called from thread mode */
		uint32_t tickstart = SchedulerTickCountGet();
		/* Count interrupts */
		while ((SchedulerTickCountGet() - tickstart) < Delay) {
			/* Go sleep, wait systick interrupt */
			__WFI();
		}
	} else {
		/* Called from interrupt mode */
		while (Delay) {
			/* Check if timer reached zero after we last checked COUNTFLAG bit */
			if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
				Delay--;
			}
		}
	}
}




