#include "stm32f4xx.h"
#include "itm.h"

void ITM_Init(void)
{
    // Enable tracing
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    // Unlock ITM
    ITM->LAR = 0xC5ACCE55;

    // Disable ITM before config
    ITM->TCR = 0;
    ITM->TER = 0;

    // SWO speed = 2 MHz
    TPI->ACPR = (SystemCoreClock / 2000000) - 1;
    // NRZ/Async
    TPI->SPPR = 2;

    // Disable formatter
    TPI->FFCR = 0x100;

    // Enable ITM + SWO + Sync
    ITM->TCR =
        ITM_TCR_ITMENA_Msk  |
        ITM_TCR_TSENA_Msk   |
        ITM_TCR_SWOENA_Msk  |
        ITM_TCR_SYNCENA_Msk;

    // Enable stimulus port 0
    ITM->TER = 1;
}
void DWT_Init(void)
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // Enable DWT
    DWT->CYCCNT = 0;                                // Reset counter
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;            // Enable cycle counter
}