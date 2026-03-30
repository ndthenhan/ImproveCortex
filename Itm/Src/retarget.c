#include "stm32f4xx.h"
#include <stdio.h>

/* int _write(int file, char *ptr, int len)
{
    //__BKPT(0);
    
    for (int i = 0; i < len; i++)
        ITM_SendChar(ptr[i]);   // CMSIS version
    return len;
    
    
} */


int _write(int file, char *ptr, int len) {
    // Only attempt to send if a debugger is active and trace is enabled
    if ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) && 
        (CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)) {
        
        for (int i = 0; i < len; i++) {
            ITM_SendChar((*ptr++));
        }
    }
    
    // Always return the length so the caller (printf) knows 
    // the data was "processed," preventing the warning and potential logic errors.
    return len;
}
