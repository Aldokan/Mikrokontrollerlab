#include <stdint.h>
#define TWI0 ((TWI*)0x40003000)

typedef struct
{
    volatile uint32_t SCL;
    volatile uint32_t SDA;
} PSEL_TYPE;


typedef struct {
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t RESERVED1[1];
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t RESERVED2[2];
    volatile uint32_t TASKS_STOP;
    volatile uint32_t RESERVED3[1];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t TASKS_RESUME;
    volatile uint32_t RESERVED4[56];
    volatile uint32_t EVENTS_STOPPED; 
    volatile uint32_t EVENTS_RXDREADY;
    volatile uint32_t RESERVED5[4];
    volatile uint32_t EVENTS_TXDSENT;
    volatile uint32_t RESERVED6[1];
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVED7[4];
    volatile uint32_t EVENTS_BB;
    volatile uint32_t RESERVED8[3];
    volatile uint32_t EVENTS_SUSPENDED;
    volatile uint32_t RESERVED9[45];
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED10[64];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED11[110];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED12[14];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVED13[1];
    PSEL_TYPE PSEL;
    volatile uint32_t RESERVED14[2];
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVED15[1];
    volatile uint32_t FREQUENCY;
    volatile uint32_t RESERVED16[24];
    volatile uint32_t ADDRESS;
} TWI;

void twi_init();
int twi_read();
