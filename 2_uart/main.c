#include "uart.h"
#include "gpio.h"
#include <stdio.h>
#include <newlib.h>

#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23

ssize_t _write(int fd, const void *buf, size_t count){
        char * letter = (char *)(buf);
        for(int i = 0; i < count; i++){
            uart_send(*letter);
            letter++;
        }
        return count;
    }

int main() {
    GPIO0->PIN_CNF[__BUTTON_A_PIN__] = 0; // button A 
	GPIO0->PIN_CNF[__BUTTON_B_PIN__] = 0; // button B
    GPIO0->PIN_CNF[21] = 1; //Row 1
    GPIO0->PIN_CNF[22] = 1; //Row 2
	GPIO0->PIN_CNF[15] = 1; //Row 3
	GPIO0->PIN_CNF[24] = 1; //Row 4
	GPIO0->PIN_CNF[19] = 1; //Row 5
    GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5] = 1;  //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5
    uart_init();
    iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
    while (1) {
        if (!(GPIO0->IN & (1<<__BUTTON_A_PIN__))) {
            uart_send('A');
        }
        if (!(GPIO0->IN & (1<<__BUTTON_B_PIN__))) {
            uart_send('B');
        }
        if(uart_read()) {
            if (GPIO0->OUT == (GPIO0->OUT |= (1<<21)))
            {
                GPIO0->OUT &= 0;
			    GPIO1->OUT &= 0;
             }
             else
             {
                 GPIO0->OUT |= (1<<21);
			     GPIO0->OUT |= (1<<22);
			     GPIO0->OUT |= (1<<15);
			     GPIO0->OUT |= (1<<24);
			     GPIO0->OUT |= (1<<19);
			     GPIO0->OUT &= ~(1<<28);
			     GPIO0->OUT &= ~(1<<11);
			     GPIO0->OUT &= ~(1<<31);
			     GPIO1->OUT &= ~(1<<5);
			     GPIO0->OUT &= ~(1<<30);
             }
           
        }
    }
    return 0;
}