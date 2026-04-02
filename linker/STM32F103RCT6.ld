ENTRY(Reset_Handler);

_estack = ORIGIN(RAM)+LENGTH(RAM);

_max_heap_size = 0x400;
_max_stack_size = 0x100;

MEMORY
{
    RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
}


SECTIONS {
    .isr_vectors : 
    {
        . = ALIGN(4); /* aligns the current location (.) to a 4-byte boundary by adding */
        KEEP(*(.isr_vectors)) /* This line of code uses the KEEP command to prevent the `.vectors` symbols from being optimized. */
        . = ALIGN(4);
    } >FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        /* --- ARM/Thumb interworking support --- */
        *(.glue_7)        /* ARM -> Thumb transition stubs (only needed if mixing ARM/Thumb) */
        *(.glue_7t)       /* Thumb -> ARM transition stubs */

        /* --- Exception / unwinding info (mainly for C++) --- */
        *(.eh_frame)      /* stack unwind & exception handling (can remove if pure C, no debug unwind) */

        /* --- Runtime init / fini hooks --- */
        KEEP(*(.init)) /* code run before main (constructors, runtime init) */
        KEEP(*(.fini)) /* code run after main (destructors) */

        . = ALIGN(4);
        _etext = .;  /* end of text section (used for copying .data from flash to RAM) */
    } >FLASH

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH

        .ARM.extab (READONLY):
    {
        . = ALIGN(4);
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        . = ALIGN(4);
    } >FLASH

    .ARM (READONLY) : 
    {
        . = ALIGN(4);
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
        . = ALIGN(4);
    } >FLASH

    .preinit_array (READONLY) :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
        . = ALIGN(4);
    } >FLASH

    .init_array (READONLY) :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
        . = ALIGN(4);
    } >FLASH

    .fini_array (READONLY) :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
        . = ALIGN(4);
    } >FLASH

    _sidata = LOADADDR(.data);
    .data : 
    {
        . = ALIGN(4);
        _sdata = .; /* defined the start address data*/
        *(.data)
        *(.data*)
        . = ALIGN(4);

        _edata = .; /* defined the end address data */
    } >RAM AT >FLASH

    . = ALIGN(4);
    .bss : 
    {
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } >RAM

    .user_heap_stack : 
    {
        . = ALIGN(8);
        PROVIDE(end = .);
        PROVIDE(_end = .);
        . = . + _max_stack_size;
        . = . + _max_heap_size;
        . = ALIGN(8);
    } >RAM
}