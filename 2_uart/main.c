#include "uart.h"
#include "gpio.h"
#include <stdio.h>

#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23

int main() {
    GPIO0->PIN_CNF[__BUTTON_A_PIN__] = 0; // button A 
	GPIO0->PIN_CNF[__BUTTON_B_PIN__] = 0; // button B
    GPIO0->PIN_CNF[21] = 1; //Row 1
    GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5] = 1;  //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5 
    uart_init();
    while (1) {
        if (!(GPIO0->IN & (1<<__BUTTON_A_PIN__))) {
            uart_send('A');
        }
        if (!(GPIO0->IN & (1<<__BUTTON_B_PIN__))) {
            uart_send('B');
        }
    }
    return 0;
}