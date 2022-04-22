#include "r_type.h"

void ADD(r_type instruction, registers * banco){//OK
    printf("ADD x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    *rd = (*rs1) + (*rs2);
}

void SUB(r_type instruction, registers * banco){//OK
    printf("SUB x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    *rd = (*rs1) - (*rs2);
}

//SLL perform logical left shifts on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2.
void SLL(r_type instruction, registers * banco) {//OK
    printf("SLL x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    int32_t amount = (*rs2) & 0b00000000000000000000000000011111;
    *rd = (*rs1) << amount;
}

//SLT perform signed compares respectively, writing 1 to rd if rs1 < rs2, 0 otherwise
void SLT(r_type instruction, registers * banco){//OK
    printf("SLT x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    if((*rs1) < (*rs2))
        (*rd) = 1;
    else 
        (*rd) = 0;
}

//SLTU perform unsigned compares respectively, writing 1 to rd if rs1 < rs2, 0 otherwise
void SLTU(r_type instruction, registers * banco) {//OK
    printf("SLTU x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t * rs2 = getRegister(instruction.rs2, banco);
    uint32_t rs1_u = (*rs1);
    uint32_t rs2_u = (*rs2);
    if(rs1_u < rs2_u)
        (*rd) = 1;
    else 
        (*rd) = 0;
}

void XOR(r_type instruction, registers * banco){//OK
    printf("XOR x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    (*rd) = (*rs1) ^ (*rs2);
}

//SRL logical right shifts on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2.
void SRL(r_type instruction, registers * banco) { //OK
    printf("SRL x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    int32_t amount = (*rs2) & 0b00000000000000000000000000011111;//lower 5 bits of register rs2.
    (*rd) = (*rs1) >> amount;
}

//SRA perform  arithmetic right shifts on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2.
void SRA(r_type instruction, registers * banco){//OK
    printf("SRA x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    int32_t amount = (*rs2) & 0b00000000000000000000000000011111;

    (*rd)= (*rs1) >>= amount;
}

void OR(r_type instruction, registers * banco){//OK
    printf("OR x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    (*rd) = (*rs1) | (*rs2);
}

void AND(r_type instruction, registers * banco){//OK
    printf("AND x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    *rd = (*rs1) & (*rs2);
}

// SLLI is a logical left shift (zeros are shifted into the lower bits);
void SLLI(r_type instruction, registers * banco){//OK
    printf("SLLI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    
    (*rd) = (*rs1) << (*rs2);
}

//SRLI is a logical right shift (zeros are shifted into the upper bits);
void SRLI(r_type instruction, registers * banco){//OK
    printf("SRLI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    (*rd) = (*rs1) >> (*rs2);
}

//and SRAI is an arithmetic right shift (the original sign bit is copied into the vacated upper bits).
       
void SRAI(r_type instruction, registers * banco){//OK
    printf("SRAI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.rs2);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
        
    (*rd) = (*rs1) >>= (*rs2);

}