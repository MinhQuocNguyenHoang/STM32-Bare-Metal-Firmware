#ifndef GPIO_H
#define GPIO_H

//============= GPIO ===================
typedef struct{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
}GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef*)0x40010800)
#define GPIOB ((GPIO_TypeDef*)0x40010C00)
#define GPIOC ((GPIO_TypeDef*)0x40011000)
#define GPIOD ((GPIO_TypeDef*)0x40011400)
#define GPIOE ((GPIO_TypeDef*)0x40011800)
#define GPIOF ((GPIO_TypeDef*)0x40011C00)
#define GPIOG ((GPIO_TypeDef*)0x40012000) 


//=============== function=============

void writePin(GPIO_TypeDef* gpio, uint8_t state, uint8_t pin);
void readPin(GPIO_TypeDef* gpio, uint8_t pin);
void tooglePin(GPIO_TypeDef* gpio, uint8_t pin);
void pinMode(GPIO_TypeDef* gpio, uint8_t mode);
#endif