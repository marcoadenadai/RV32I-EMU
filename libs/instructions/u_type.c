#include "u_type.h"

// LUI (load upper immediate) is used to build 32-bit constants and uses the U-type format. 
// LUI places the U-immediate value in the top 20 bits of the destination register rd, 
// filling in the lowest 12 bits with zeros.
void LUI(u_type instruction, registers * banco){//OK
    printf("LUI x%d, %d",instruction.rd, instruction.imm);//ok

    int32_t imm_value = instruction.imm <<= 12;
    int32_t* rd = getRegister(instruction.rd, banco);

    *rd = imm_value;
}

// AUIPC (add upper immediate to pc) is used to build pc-relative addresses and uses the U-type format. 
// AUIPC forms a 32-bit offset from the 20-bit U-immediate, filling in the lowest 12 bits with zeros, 
// adds this offset to the pc, then places the result in register rd.
void AUIPC(u_type instruction, registers * banco, int PC){//OK
    printf("AUIPC x%d, %d",instruction.rd, instruction.imm);//ok

    int32_t imm_value = instruction.imm <<= 12;
    int32_t* rd = getRegister(instruction.rd, banco);

    (*rd) = (PC * 4) + imm_value;
}