#ifndef MAIN_H_
#define MAIN_H_


#define MAX_TASKS 5	// 4 user task plus 1 idle task

/* some stack memory calculation */
#define SIZE_TASK_STACK 		1024U
#define SIZE_SCHED_STACL		1024U

#define SRAM_START				0x20000000U	// start of SRAM
#define SIZE_SRAM				((64) * (1024))	// means 1KB
#define SRAM_END				((SRAM_START) + (SIZE_SRAM))

/* define a couple of macros describing a stack information of various user task */
#define T1_STACK_START			SRAM_END
#define T2_STACK_START			((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T3_STACK_START			((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START			((SRAM_END) - (3 * SIZE_TASK_STACK))
#define IDLE_STACK_START		((SRAM_END) - (4 * SIZE_TASK_STACK))
#define SCHED_STACK_START		((SRAM_END) - (5 * SIZE_TASK_STACK))

#define TICK_HZ 1000U

#define HSI_CLOCK			8000000U	// rm 9.2 clock
#define SYSTICK_TIM_CLK 	HSI_CLOCK

#define DUMMY_XPSR	0x01000000U

#define TASK_READY_STATE 0x00
#define TASK_BLOCKED_STATE 0xFF

#define INTERRUPT_DISABLE() do{__asm volatile ("MOV R0,#0x1"); __asm volatile ("MSR PRIMASK, R0"); } while(0)

#define INTERRUPT_ENABLE() do{__asm volatile ("MOV R0,#0x0"); __asm volatile ("MSR PRIMASK, R0"); } while(0)


#endif /* MAIN_H_ */