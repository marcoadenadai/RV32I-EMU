#pragma once
#include "../instructions.h"

void ADD(r_type instruction, registers * banco);
void SUB(r_type instruction, registers * banco);
void SLL(r_type instruction, registers * banco);
void SLLI(r_type instruction, registers * banco);
void SRLI(r_type instruction, registers * banco);
void SRAI(r_type instruction, registers * banco);
void SLT(r_type instruction, registers * banco);
void SLTU(r_type instruction, registers * banco);
void XOR(r_type instruction, registers * banco);
void SRL(r_type instruction, registers * banco);
void SRA(r_type instruction, registers * banco);
void OR(r_type instruction, registers * banco);
void AND(r_type instruction, registers * banco);