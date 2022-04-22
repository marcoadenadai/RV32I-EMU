#pragma once
#include "instructions.h"

void printBin (unsigned n);
void dumpMem(void * memory, unsigned size, const char * fileName);
void dumpRegisters(registers banco_reg);
unsigned long loadInstructions(const char * filename, gen_type * instructList);

