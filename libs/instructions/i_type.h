#pragma once
#include "../instructions.h"

void JALR(i_type instruction, registers * banco, int PC);
void LB(i_type instruction, registers * banco, int8_t *memory); // <-- mem     // VALIDAR
void LH(i_type instruction, registers * banco, int16_t *memory); // <-- mem     // VALIDAR
void LW(i_type instruction, registers * banco, int32_t *memory); // <-- mem     // VALIDAR
void LBU(i_type instruction, registers * banco, int32_t *memory); // <-- mem    // VALIDAR
void LHU(i_type instruction, registers * banco, int32_t *memory); // <-- mem    // VALIDAR
void ADDI(i_type instruction, registers * banco);
void SLTI(i_type instruction, registers * banco);
void SLTIU(i_type instruction, registers * banco);
void XORI(i_type instruction, registers * banco);
void ORI(i_type instruction, registers * banco);
void ANDI(i_type instruction, registers * banco);