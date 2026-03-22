#include "stm32f4xx.h"
//#include "itm.h"
#include <stdio.h>

int _write(int file, char *ptr, int len)
{
    __BKPT(0);
    for (int i = 0; i < len; i++)
        ITM_SendChar(ptr[i]);   // CMSIS version
    return len;
}