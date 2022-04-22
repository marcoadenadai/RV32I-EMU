#include "b_type.h"

//Branch instructions compare two registers. BEQ and BNE take the branch if registers rs1 and rs2 are equal or unequal respectively. BLT and BLTU take the branch if rs1 is less than rs2, using signed and unsigned comparison respectively. BGE and BGEU take the branch if rs1 is greater than or equal to rs2, using signed and unsigned comparison respectively. Note, BGT, BGTU, BLE, and BLEU can be synthesized by reversing the operands to BLT, BLTU, BGE, and BGEU, respectively.
void BEQ(b_type instruction, registers * banco, int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    //Take the adress
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)
    
    if((*rs1) == (*rs2)){
        (*PC) = NextAddr;
    }
    printf("BEQ x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}

void BNE(b_type instruction, registers * banco, int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    //Get the adress
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    if((*rs1) != (*rs2)){
        (*PC) = NextAddr;
    }
    printf("BNE x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}

void BLT(b_type instruction, registers * banco, int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    //Take the adress
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    if((*rs1) < (*rs2)){
        (*PC) = NextAddr;
    }
    printf("BLT x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}

void BGE(b_type instruction, registers * banco, int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    
    //Take the adress
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    if((*rs1) >= (*rs2)){
        (*PC) = NextAddr;
    }
    printf("BGE x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}

void BLTU(b_type instruction, registers * banco, int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);
    
    uint32_t rs1_u = (*rs1);
    uint32_t rs2_u = (*rs2);
    //Take the adress
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    if(rs1_u < rs2_u){
        (*PC) = NextAddr;
    }
    printf("BLTU x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}

void BGEU(b_type instruction, registers * banco,  int *PC){//OK
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rs2 = getRegister(instruction.rs2, banco);

    uint32_t rs1_u = (*rs1);
    uint32_t rs2_u = (*rs2);
    int32_t Imm = getImmB(instruction.imm1, instruction.imm2);
    int32_t NextAddr = (*PC) + (Imm/4);
    NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    if(rs1_u >= rs2_u){
        // int IndexMemInst = getImmB(instruction.imm1, instruction.imm2) / 4; // TODO !!! ATENCAO
        (*PC) = NextAddr;
    }
    printf("BGEU x%d, x%d, %d",instruction.rs1, instruction.rs2, Imm);//ok
}