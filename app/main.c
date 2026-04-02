#include "gpio.h"
#include "rcc.h"
#include <stdio.h>

void delay_ms(uint16_t ms)
{
    volatile unsigned long j = 0;
    for (uint16_t i = 0; i < ms; i++)
    {
        for (j = 0; j < 1500; j++)
        {
            ;
        }
    }
}

int main()
{
    RCC_Enable_GPIO(RCC_GPIOB);
    pinMode(GPIOB, GPIO_MODE_OUTPUT_50MHZ_PUSH_PULL, 13);
    while (1)
    {
        writePin(GPIOB, 1, 13);
        delay_ms(5000);
        writePin(GPIOB, 0, 13);
        delay_ms(5000);
    }
}