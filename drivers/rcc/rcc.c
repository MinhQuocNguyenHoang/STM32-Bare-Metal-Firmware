#include <stdio.h>
#include "rcc.h"

//=================== GPIO ===================
void RCC_Enable_GPIO(RCC_GPIO_t gpio)
{
    if (gpio > 2 && gpio < 4)
        return;
    RCC->APB2ENR |= (1 << (gpio + 2));
}