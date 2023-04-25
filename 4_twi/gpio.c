#include <stdint.h>
#include "gpio.h"

void gpio_init(){
	  GPIO0->PIN_CNF[14] = 0; // button A
	  GPIO0->PIN_CNF[23] = 0; // button B

	  // Configure leds
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
};

void gpio_lights_on(){
   GPIO0->OUTSET = (1<<21);
   GPIO0->OUTSET = (1<<22);
   GPIO0->OUTSET = (1<<15);
   GPIO0->OUTSET = (1<<24);
   GPIO0->OUTSET = (1<<19);
};

void gpio_lights_off(){
   GPIO0->OUTCLR = (1<<21);
   GPIO0->OUTCLR = (1<<22);
   GPIO0->OUTCLR = (1<<15);
   GPIO0->OUTCLR = (1<<24);
   GPIO0->OUTCLR = (1<<19);
};
