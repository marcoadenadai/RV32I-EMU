#pragma once
#include "../instructions.h"

void BEQ(b_type instruction, registers * banco, int *PC);
void BNE(b_type instruction, registers * banco, int *PC);
void BLT(b_type instruction, registers * banco, int *PC);
void BGE(b_type instruction, registers * banco, int *PC);
void BLTU(b_type instruction, registers * banco, int *PC);
void BGEU(b_type instruction, registers * banco, int *PC);