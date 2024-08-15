// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#include "firmware.h"

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

	print_str("Stored value in 0x1000\n");
}
