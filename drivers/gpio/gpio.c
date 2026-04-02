#include <stdio.h>
#include "gpio.h"

void writePin(GPIO_TypeDef *gpio, uint8_t state, uint8_t pin)
{
    if (state)
    {
        gpio->ODR |= (1 << pin);
    }
    gpio->ODR &= ~(1 << pin);
}

int readPin(GPIO_TypeDef *gpio, uint8_t pin)
{
    return (gpio->IDR >> pin) & 0x1;
}

void togglePin(GPIO_TypeDef *gpio, uint8_t pin)
{
    gpio->ODR ^= (1 << pin);
}

int isValidMode(uint8_t mode)
{
    return (mode <= 0xF);
}

void pinMode(GPIO_TypeDef *gpio, GPIO_Mode mode, uint8_t pin)
{
    if (pin >= 15 || !isValidMode(mode))
        return;

    if (pin < 8)
    {
        gpio->CRL &= ~(0xF << (pin * 4));
        gpio->CRL |= (mode << (pin * 4));
    }
    gpio->CRH &= ~(0xF << ((pin - 8) * 4));
    gpio->CRH |= (mode << ((pin - 8) * 4));
}
