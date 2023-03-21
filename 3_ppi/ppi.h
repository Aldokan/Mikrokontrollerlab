#ifndef PPI_H
#define PPI_H
#include <stdint.h>

#define PPI ((NRF_PPI_REG*)__PPI_BASE_ADDRESS__)

typedef struct {
	uint32_t EN;
	uint32_t DIS;
} PPI_TASKS_TYPE;

typedef struct {
	uint32_t EEP;
	uint32_t TEP;
} PPI_CHANNEL_TYPE;

typedef struct {
	// Tasks
	volatile PPI_TASKS_TYPE PPI_TASKS[6];
	// Registers
	volatile uint32_t RESERVED0[__RESERVED1_0_SIZE__];
	volatile uint32_t CHEN;
	volatile uint32_t CHENSET;
	volatile uint32_t CHENCLR;
	volatile uint32_t RESERVED1[__RESERVED1_1_SIZE__];
	volatile PPI_CHANNEL_TYPE PPI_CH[20];
	volatile uint32_t RESERVED2[__RESERVED1_2_SIZE__];
	volatile uint32_t CHG[6];
	volatile uint32_t RESERVED3[__RESERVED1_3_SIZE__];
	volatile uint32_t FORK_TEP[32];
} NRF_PPI_REG;

#endif

void init_PPI();
