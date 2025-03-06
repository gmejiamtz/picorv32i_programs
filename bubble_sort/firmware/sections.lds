/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
*/

MEMORY {
	main_mem : ORIGIN = 0x00001000, LENGTH = 0x00004000
	code : ORIGIN = 0x00000000, LENGTH = 0x00001000
	sorter_mem : ORIGIN = 0x00005000, LENGTH = 0x00004000 /* Reserve 16KB for the array */
}

SECTIONS {
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        *(.srodata)
        *(.srodata*)
        . = ALIGN(4);
        _etext = .;
        _sidata = _etext;
    } >code
    .data : AT ( _sidata )
    {
        . = ALIGN(4);
        _sdata = .;
        _ram_start = .;
        . = ALIGN(4);
        *(.data)
        *(.data*)
        *(.sdata)
        *(.sdata*)
        . = ALIGN(4);
        _edata = .;
    } >main_mem
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(.sbss)
        *(.sbss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >main_mem
    /* Define the array section at 0x3000 */
    .sorter_section 0x3000 :
    {
        KEEP(*(.my_array_section))
    } >sorter_mem

}
