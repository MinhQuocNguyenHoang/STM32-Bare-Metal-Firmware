#include <stdint.h>

#define RAM_START 0x20000000
#define RAM_SIZE (64U * 1024U) // 64KB
#define RAM_END (RAM_START) + RAM_SIZE

#define STACK_START RAM_END

int main(void);
void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void MemoryMange_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DebugMonitor_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias(" Default_Handler")));

/* External Interrupts */
void WWDG_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void PVD_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TAMPER_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void RTC_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void FLASH_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void RCC_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI0_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI1_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI3_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI4_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel1_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel3_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel4_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel5_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel6_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void DMA1_Channel7_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void ADC1_2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void CAN1_TX_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void CAN1_RX0_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void CAN1_RX1_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void CAN1_SCE_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI9_5_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM1_BRK_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM1_UP_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM1_TRG_COM_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM1_CC_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM3_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void TIM4_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void I2C1_EV_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void I2C1_ER_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void I2C2_EV_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void I2C2_ER_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void SPI1_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void SPI2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void USART1_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void USART2_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void USART3_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void EXTI15_10_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void RTCAlarm_Handler(void) __attribute__((weak, alias(" Default_Handler")));
void OTG_FS_WKUP_Handler(void) __attribute__((weak, alias(" Default_Handler")));

uint32_t vector[] __attribute__((section(".vector"))) = {
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemoryMange_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,

    /* External Interrupts */
    (uint32_t)&WWDG_Handler,
    (uint32_t)&PVD_Handler,
    (uint32_t)&TAMPER_Handler,
    (uint32_t)&RTC_Handler,
    (uint32_t)&FLASH_Handler,
    (uint32_t)&RCC_Handler,
    (uint32_t)&EXTI0_Handler,
    (uint32_t)&EXTI1_Handler,
    (uint32_t)&EXTI2_Handler,
    (uint32_t)&EXTI3_Handler,
    (uint32_t)&EXTI4_Handler,
    (uint32_t)&DMA1_Channel1_Handler,
    (uint32_t)&DMA1_Channel2_Handler,
    (uint32_t)&DMA1_Channel3_Handler,
    (uint32_t)&DMA1_Channel4_Handler,
    (uint32_t)&DMA1_Channel5_Handler,
    (uint32_t)&DMA1_Channel6_Handler,
    (uint32_t)&DMA1_Channel7_Handler,
    (uint32_t)&ADC1_2_Handler,
    (uint32_t)&CAN1_TX_Handler,
    (uint32_t)&CAN1_RX0_Handler,
    (uint32_t)&CAN1_RX1_Handler,
    (uint32_t)&CAN1_SCE_Handler,
    (uint32_t)&EXTI9_5_Handler,
    (uint32_t)&TIM1_BRK_Handler,
    (uint32_t)&TIM1_UP_Handler,
    (uint32_t)&TIM1_TRG_COM_Handler,
    (uint32_t)&TIM1_CC_Handler,
    (uint32_t)&TIM2_Handler,
    (uint32_t)&TIM3_Handler,
    (uint32_t)&TIM4_Handler,
    (uint32_t)&I2C1_EV_Handler,
    (uint32_t)&I2C1_ER_Handler,
    (uint32_t)&I2C2_EV_Handler,
    (uint32_t)&I2C2_ER_Handler,
    (uint32_t)&SPI1_Handler,
    (uint32_t)&SPI2_Handler,
    (uint32_t)&USART1_Handler,
    (uint32_t)&USART2_Handler,
    (uint32_t)&USART3_Handler,
    (uint32_t)&EXTI15_10_Handler,
    (uint32_t)&RTCAlarm_Handler,
    (uint32_t)&OTG_FS_WKUP_Handler};

void Default_Handler(void)
{
    while (1)
        ;
}

void Reset_Handler(void)
{
    // copy data in flash to RAM
    extern uint32_t _sidata; // data on flash
    extern uint32_t _sdata;  // position begin of .data in RAM
    extern uint32_t _edata;  // position end of .data in RAM
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata)
    {
        *dst++ = *src++;
    }

    // Intialize bss equal 0 on RAM
    extern uint32_t _sbss;
    extern uint32_t _ebss;

    uint32_t *bss = &_sbss;

    while (bss < &_ebss)
    {
        *bss++ = 0;
    }

    // call main
    main();
}

// note: lý do tại sao lại có bảng vector trong layout memory và startup vì CPU sẽ chạy theo việc nhảy vào địa chỉ
// Ví dụ khi MCU nạp code hoặc reset thì MCU sẽ nhảy vào địa chỉ của IRQ Reset_Handler() vầ thực hiện
// các bước trong hàm handler như copy data qua flash, khởi tạo bss bằng 0 và chạy hàm main.
// Hoặc nếu chúng ta có xài một IRQ ngoài nào đó xảy ra thì chúng ta bắt buộc khai báo IRQ đó để mcu biết được địa chỉ của nó và nhảy
// tới, đồng thời lý do các hàm IRQ đều xài weak alias để cho phép dev có thể ghi đè vô hàm đó để sửa logic khi ngắt xảy ra theo ý
// của họ (chẳng hạn như khi nhấn nút IRQ EXIT0 xảy ra ngắt mcu sẽ nhảy đến vector EXIT0 đó và thực hiện logic bạn code trong hàm
// EXIT0_Handler)
//=> nên vì thế chúng ta bắt buộc khai báo hết IRQ có trong mcu để phục vụ việc trên