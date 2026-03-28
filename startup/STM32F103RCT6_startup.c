#include <stdint.h>

#define RAM_START 0x2000000
#define RAM_SIZE (64U * 1024U) // 64KB
#define RAM_END (RAM_START) + RAM_SIZE

#define STACK_START RAM_END

void Reset_Handler(void) {}

uint32_t vector[] __attribute__((section(".vector"))) = {
    STACK_START,
    (uint32_t)&Reset_Handler,
};