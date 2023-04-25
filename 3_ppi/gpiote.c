#include "gpiote.h"
#include "gpio.h"

void gpio_init() {
    //GPIO0->PIN_CNF[14] = 0; // button A
    //GPIOTE->CONFIG[0]= 0b00000000000000100000111000000010; //0000000000000010000111000000010

    GPIO0->PIN_CNF[28] = 1; //Col 1
    GPIO0->PIN_CNF[11] = 1; //Col 2
    GPIO0->PIN_CNF[31] = 1; //Col 3
    GPIO1->PIN_CNF[5] = 1;  //Col 4
    GPIO0->PIN_CNF[30] = 1; //Col 5 
    GPIO0->OUT &= ~(1<<28);
    GPIO0->OUT &= ~(1<<11);
    GPIO0->OUT &= ~(1<<31);
    GPIO1->OUT &= ~(1<<5);
    GPIO0->OUT &= ~(1<<30);

    //Forsyningspinner
    //GPIO0__->PIN_CNF[21] = 1; //Row 1
	//__GPIO0__->PIN_CNF[22] = 1; //Row 2
	//__GPIO0__->PIN_CNF[15] = 1; //Row 3
	//__GPIO0__->PIN_CNF[24] = 1; //Row 4
	//__GPIO0__->PIN_CNF[19] = 1; //Row 5

    //GPIOTE->CONFIG[0]= 0b0000 0000 0000 0010 0000 1110 0000 0001;
    GPIOTE->CONFIG[0] |= 1;
    GPIOTE->CONFIG[0] |= 14<<8;
    GPIOTE->CONFIG[0] |= 0<<13;
    GPIOTE->CONFIG[0] |= 2<<16;
    GPIOTE->CONFIG[0] |= 0<<20;
    
    //GPIOTE->CONFIG[1]= 0b0000 0000 0000 0011 0001 0101 0000 0011;
    GPIOTE->CONFIG[1] |= 3;
    GPIOTE->CONFIG[1] |= 21<<8;
    GPIOTE->CONFIG[1] |= 0<<13;
    GPIOTE->CONFIG[1] |= 3<<16;
    GPIOTE->CONFIG[1] |= 1<<20;

    //GPIOTE->CONFIG[2]= 0b0000 0000 0000 0011 0001 0110 0000 0011;
    GPIOTE->CONFIG[2] |= 3;
    GPIOTE->CONFIG[2] |= 22<<8;
    GPIOTE->CONFIG[2] |= 0<<13;
    GPIOTE->CONFIG[2] |= 3<<16;
    GPIOTE->CONFIG[2] |= 1<<20;

    //GPIOTE->CONFIG[3]= 0b0000 0000 0000 0011 0000 1111 0000 0011;
    GPIOTE->CONFIG[3] |= 3;
    GPIOTE->CONFIG[3] |= 15<<8;
    GPIOTE->CONFIG[3] |= 0<<13;
    GPIOTE->CONFIG[3] |= 3<<16;
    GPIOTE->CONFIG[3] |= 1<<20;

    //GPIOTE->CONFIG[4]= 0b0000 0000 0000 0011 0001 1000 0000 0011;
    GPIOTE->CONFIG[4] |= 3;
    GPIOTE->CONFIG[4] |= 24<<8;
    GPIOTE->CONFIG[4] |= 0<<13;
    GPIOTE->CONFIG[4] |= 3<<16;
    GPIOTE->CONFIG[4] |= 1<<20;

    //GPIOTE->CONFIG[5]= 0b0000 0000 0000 0011 0001 0011 0000 0011;
    GPIOTE->CONFIG[5] |= 3;
    GPIOTE->CONFIG[5] |= 19<<8;
    GPIOTE->CONFIG[5] |= 0<<13;
    GPIOTE->CONFIG[5] |= 3<<16;
    GPIOTE->CONFIG[5] |= 1<<20;


    
    
}

