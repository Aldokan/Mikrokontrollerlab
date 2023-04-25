#include "twi.h"

void twi_init() {
    TWI0->PSEL.SDA &= ~30;
    TWI0->PSEL.SDA &= ~(0<<5);
    TWI0->PSEL.SDA &= ~(1<<31);
    TWI0->PSEL.SCL &= ~28;
    TWI0->PSEL.SCL &= ~(0<<5);
    TWI0->PSEL.SCL &= ~(1<<31);
    TWI0->ADDRESS = 0x19;
    TWI0->TASKS_STARTRX = 1;
} 

int twi_read() {
    int out;
    while (TWI0->EVENTS_RXDREADY != 1) {
        int test = TWI0->EVENTS_RXDREADY;
        out = TWI0->RXD;
    }
    TWI0->EVENTS_RXDREADY = 0;
    return out;
}