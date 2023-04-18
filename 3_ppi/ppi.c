#include "ppi.h"
#include "gpiote.h"

void init_PPI() {
for (int i = 0; i < 5; i++)
    {
        PPI->PPI_CH[i].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
        PPI->PPI_CH[i].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[i+1]);
    }
    PPI->CHENSET=0b00000000000000000000000000011111;

}