#include <stdint.h>

#define __GPIO_BASE_ADDRESS0__ 0x50000000
#define __GPIO_BASE_ADDRESS1__ 0x50000300
#define __RESERVED1_0_SIZE__ 118
#define __RESERVED1_1_SIZE__ 118
#define __GPIO0__ ((NRF_GPIO_REGS0*)__GPIO_BASE_ADDRESS0__) //gpio 0 base adress
#define __GPIO1__ ((NRF_GPIO_REGS1*)__GPIO_BASE_ADDRESS1__) //gpio 1 base adress
#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[__RESERVED1_0_SIZE__];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[__RESERVED1_1_SIZE__];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

int main(){

	// Configure leds (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	__GPIO0__->PIN_CNF[21] = 1; //Row 1
	__GPIO0__->PIN_CNF[22] = 1; //Row 2
	__GPIO0__->PIN_CNF[15] = 1; //Row 3
	__GPIO0__->PIN_CNF[24] = 1; //Row 4
	__GPIO0__->PIN_CNF[19] = 1; //Row 5

	__GPIO0__->PIN_CNF[28] = 1; //Col 1
	__GPIO0__->PIN_CNF[11] = 1; //Col 2
	__GPIO0__->PIN_CNF[31] = 1; //Col 3
	__GPIO1__->PIN_CNF[5] = 1;  //Col 4
	__GPIO0__->PIN_CNF[30] = 1; //Col 5 
	
	// Configure buttons (dere må sjekke selv hvilken GPIO modul de ulike knappene tilhører)
	__GPIO0__->PIN_CNF[__BUTTON_A_PIN__] = 0; // button A 
	__GPIO0__->PIN_CNF[__BUTTON_B_PIN__] = 0; // button B
	
	int sleep = 0;
	while(1){

		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */
		if (!(__GPIO0__->IN & (1<<__BUTTON_B_PIN__))) {
			__GPIO0__->OUT |= (1<<21);
			__GPIO0__->OUT |= (1<<22);
			__GPIO0__->OUT |= (1<<15);
			__GPIO0__->OUT |= (1<<24);
			__GPIO0__->OUT |= (1<<19);
			__GPIO0__->OUT &= ~(1<<28);
			__GPIO0__->OUT &= ~(1<<11);
			__GPIO0__->OUT &= ~(1<<31);
			__GPIO1__->OUT &= ~(1<<5);
			__GPIO0__->OUT &= ~(1<<30);
		}

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */
		if (!(__GPIO0__->IN & (1<<__BUTTON_A_PIN__))) {
			__GPIO0__->OUT &= 0;
			__GPIO1__->OUT &= 0;
		}

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}
