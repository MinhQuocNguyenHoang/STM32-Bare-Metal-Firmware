#ifndef GPIO_H
#define GPIO_H

//============= GPIO ===================
typedef enum
{
    GPIO_MODE_INPUT_ANALOG = 0x0,
    GPIO_MODE_INPUT_FLOATING = 0x4,
    GPIO_MODE_INPUT_PULL = 0x8, // pull up : set ODR to 1, pull down: set ODR to 0

    GPIO_MODE_OUTPUT_10MHZ_PUSH_PULL = 0x1,
    GPIO_MODE_OUTPUT_2MHZ_PUSH_PULL = 0x2,
    GPIO_MODE_OUTPUT_50MHZ_PUSH_PULL = 0x3,

    GPIO_MODE_OUTPUT_10MHZ_OPEN_DRAIN = 0x5,
    GPIO_MODE_OUTPUT_2MHZ_OPEN_DRAIN = 0x6,
    GPIO_MODE_OUTPUT_50MHZ_OPEN_DRAIN = 0x7,
} GPIO_Mode;

typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *)0x40010800)
#define GPIOB ((GPIO_TypeDef *)0x40010C00)
#define GPIOC ((GPIO_TypeDef *)0x40011000)
#define GPIOD ((GPIO_TypeDef *)0x40011400)
#define GPIOE ((GPIO_TypeDef *)0x40011800)
#define GPIOF ((GPIO_TypeDef *)0x40011C00)
#define GPIOG ((GPIO_TypeDef *)0x40012000)

//=============== function=============

void writePin(GPIO_TypeDef *gpio, uint8_t state, uint8_t pin);
int readPin(GPIO_TypeDef *gpio, uint8_t pin);
void togglePin(GPIO_TypeDef *gpio, uint8_t pin);
void pinMode(GPIO_TypeDef *gpio, uint8_t mode, uint8_t pin);

#endif