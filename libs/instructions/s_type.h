#pragma once
#include "../instructions.h"

void SB(s_type instruction, registers * banco, int8_t * memory); // <-- mem    // VALIDAR
void SH(s_type instruction, registers * banco, int16_t * memory); // <-- mem    // VALIDAR
void SW(s_type instruction, registers * banco, int32_t * memory); // <-- mem    // VALIDAR
