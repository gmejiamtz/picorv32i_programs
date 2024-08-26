// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#include "firmware.h"

void hello(void);

void hello(void)
{
    uint32_t address = 0x1000; // Example memory address
	uint32_t value_s = 0x0F00;

	__asm__ volatile (
		"sw %0, 0(%1)"   // Store word from %0 to address in %1
		:                // No output operands
		: "r" (value_s),   // Input operand: %0 (value) will be stored in a register
		"r" (address)  // Input operand: %1 (address) will be stored in a register
    );

    uint32_t value;

	// Inline assembly to read the value from the memory address
	__asm__ volatile (
		"lw %0, 0(%1)"   // Load word from address in %1 into %0
		: "=r" (value)   // Output operand: %0 (value) will be stored in a register
		: "r" (address)  // Input operand: %1 (address) will be stored in a register
	);

    uint32_t result;

    __asm__ volatile (
        "addi x1, zero, 10\n"  // Adds 1000 to zero and stores it in x1 (result)
        ".word 0xa00e00b" // Custom instruction
        : "=r" (result)  // Output operand: %0 corresponds to x1 (result will be stored here)
        :                // No input operands
        : "x1"           // Clobber list: indicate that x1 is modified
    );

	while(1);
}
