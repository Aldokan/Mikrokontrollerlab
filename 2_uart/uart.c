#include <stdint.h>
#include "gpio.h"
#define UART ((NRF_UART_REG*)0x40002000)


typedef struct {
   volatile uint32_t TASKS_STARTRX;
   volatile uint32_t TASKS_STOPRX;
   volatile uint32_t TASKS_STARTTX;
   volatile uint32_t TASKS_STOPTX;
   volatile uint32_t RESERVED_1[3];
   volatile uint32_t TASKS_SUSPEND;
   volatile uint32_t RESERVED_2[56];
   volatile uint32_t EVENTS_CTS;
   volatile uint32_t EVENTS_NCTS;
   volatile uint32_t EVENTS_RXDRDY;
   volatile uint32_t RESERVED_3[4];
   volatile uint32_t EVENTS_TXDRDY;
   volatile uint32_t RESERVED_4[1];
   volatile uint32_t EVENTS_ERROR;
   volatile uint32_t RESERVED_5[7];
   volatile uint32_t EVENTS_RXTO;
   volatile uint32_t RESERVED_6[46];
   volatile uint32_t SHORTS;
   volatile uint32_t RESERVED_7[64];
   volatile uint32_t INTENSET;
   volatile uint32_t INTENCLR;
   volatile uint32_t RESERVED_8[93];
   volatile uint32_t ERRORSRC;
   volatile uint32_t RESERVED_9[31];
   volatile uint32_t ENABLE;
   volatile uint32_t RESERVED_10[1];
   volatile uint32_t PSELRTS;
   volatile uint32_t PSELTXD;
   volatile uint32_t PSELCTS;
   volatile uint32_t PSELRXD;
   volatile uint32_t RXD;
   volatile uint32_t TXD;
   volatile uint32_t RESERVED_11[1];
   volatile uint32_t BAUDRATE;
   volatile uint32_t RESERVED_12[17];
   volatile uint32_t CONFIG;
} NRF_UART_REG;

void uart_init() {
    GPIO0->PIN_CNF[6] = 0;
    GPIO1->PIN_CNF[8] = 1;
    UART->PSELRXD = 0x28; // 0b1.01000 - Port 1, Pin 8
    UART->PSELTXD = 0x06; // 0b0.00110 - Port 0, Pin 6
    UART->PSELRTS = (1<<31);
    UART->PSELCTS = (1<<31);
    UART->BAUDRATE = 0x00275000;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter) {
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while (!UART->EVENTS_TXDRDY) {}
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;
}

char uart_read() {
    if (UART->EVENTS_RXDRDY == 1) {
        char out = UART->RXD;
        UART->EVENTS_RXDRDY = 0;
        return out;
    } else {
        return '\0';
    } 
}