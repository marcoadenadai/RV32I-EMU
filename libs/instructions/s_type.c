#include "s_type.h"

//The SW, SH, and SB instructions store 32-bit, 16-bit, and 8-bit values from the low bits of register rs2 to memory.
//It computes an effective address by adding the zero-extended offset, scaled by 4, to the base address in register rs1
void SB(s_type instruction, registers * banco, int8_t *memory){//VALIDAR
    int16_t imm_value = getImmS(instruction.imm1, instruction.imm2);
    printf("SB %d, %d(x%d)",instruction.rs1, imm_value, instruction.rs2);//ok 
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + imm_value;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, imm_value);

    int8_t * data = &memory[effectiveAddress];
    int32_t * rs2 = getRegister(instruction.rs2, banco);
    *data = *((int8_t*)rs2);
}

void SH(s_type instruction, registers * banco, int16_t *memory){//VALIDAR
    int16_t imm_value = getImmS(instruction.imm1, instruction.imm2);
    printf("SB %d, %d(x%d)",instruction.rs1, imm_value, instruction.rs2);//ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + imm_value;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, imm_value);

    int16_t * data = &memory[effectiveAddress];
    int32_t * rs2 = getRegister(instruction.rs2, banco);
    *data = *((int16_t*)rs2);
}

void SW(s_type instruction, registers * banco, int32_t *memory){//VALIDAR
    int16_t imm_value = getImmS(instruction.imm1, instruction.imm2);
    printf("SB %d, %d(x%d)",instruction.rs1, imm_value, instruction.rs2);//ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + imm_value;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, imm_value);

    int32_t * data = &memory[effectiveAddress];
    int32_t * rs2 = getRegister(instruction.rs2, banco);
    *data = *(rs2);
}