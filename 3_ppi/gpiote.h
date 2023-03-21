#ifndef GPIOTE_H
#define GPIOTE_H
#include <stdint.h>

#define GPIOTE ((NRF_GPIOTE_REG*)__GPIOTE_BASE_ADDRESS__)

typedef struct {
	// Tasks
	volatile uint32_t TASKS_OUT[8];
	volatile uint32_t RESERVED0[__RESERVED1_0_SIZE__];
	volatile uint32_t TASKS_SET[8];
	volatile uint32_t RESERVED1[__RESERVED1_1_SIZE__];
	volatile uint32_t TASKS_CLR[8];
	// Events
	volatile uint32_t RESERVED2[__RESERVED1_2_SIZE__];
	volatile uint32_t EVENTS_IN[8];
	volatile uint32_t RESERVED3[__RESERVED1_3_SIZE__];
	volatile uint32_t EVENTS_PORT;
	// Registers
	volatile uint32_t RESERVED4[__RESERVED1_4_SIZE__];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED5[__RESERVED1_5_SIZE__];
	volatile uint32_t CONFIG[8];
} NRF_GPIOTE_REG;

#endif
