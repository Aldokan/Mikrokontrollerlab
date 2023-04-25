#include <stdio.h>
#include <stdint.h>
#include "twi.h"
#include "gpio.h"
#include "uart.h"
#define __GPIO_BASE_ADDRESS0__ 0x50000000
#define __GPIO_BASE_ADDRESS1__ 0x50000300
#define __GPIO0__ ((NRF_GPIO_REGS0*)__GPIO_BASE_ADDRESS0__) //gpio 0 base adress
#define __GPIO1__ ((NRF_GPIO_REGS1*)__GPIO_BASE_ADDRESS1__) //gpio 1 base adress

int main() {
    twi_init();
    uart_init();
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
    while (1) {
        switch (twi_read())
        {
        case 1: {// up
            __GPIO0__->OUT &= 0;
			__GPIO1__->OUT &= 0;
            __GPIO0__->OUT &= ~(1<<31);
            __GPIO0__->OUT |= (1<<21);
            break;
        }
        
        case 2: { // down
            __GPIO0__->OUT &= 0;
			__GPIO1__->OUT &= 0;
            __GPIO0__->OUT &= ~(1<<31);
            __GPIO0__->OUT |= (1<<22);
            break;
        }

        case 3: { // left
            __GPIO0__->OUT &= 0;
			__GPIO1__->OUT &= 0;
            __GPIO0__->OUT &= ~(1<<28);
            __GPIO0__->OUT |= (1<<15);
            break;
        }

        case 4: { // right
            __GPIO0__->OUT &= 0;
			__GPIO1__->OUT &= 0;
            __GPIO0__->OUT &= ~(1<<30);
            __GPIO0__->OUT |= (1<<15);
            break;
        }
        
        default: {
            __GPIO0__->OUT |= (1<<21);
			__GPIO0__->OUT |= (1<<22);
			__GPIO0__->OUT |= (0<<15);
			__GPIO0__->OUT |= (1<<24);
			__GPIO0__->OUT |= (1<<19);
			__GPIO0__->OUT &= ~(0<<28);
			__GPIO0__->OUT &= ~(1<<11);
			__GPIO0__->OUT &= ~(0<<31);
			__GPIO1__->OUT &= ~(0<<5);
			__GPIO0__->OUT &= ~(0<<30);
        }
            break;
        }
    }
    
    return 0;
}