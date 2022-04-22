#include "i_type.h"

//The indirect jump instruction JALR (jump and link register) uses the I-type encoding. The target address is obtained by adding the 12-bit signed I-immediate to the register rs1, then setting the least-significant bit of the result to zero. The address of the instruction following the jump (pc+4) is written to register rd. Register x0 can be used as the destination if the result is not required.
void JALR(i_type instruction, registers * banco, int PC){//OK
    printf("JALR x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.imm);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    int32_t* rd = getRegister(instruction.rd, banco);
    uint32_t target = instruction.imm + (*rs1);
    target = target & 0b11111111111111111111111111111110;
    (*rd) = PC + 1;
}

//LB loads a 8-bit value from memory, then sign-extends to 32-bits before storing in rd
//The effective byte address is obtained by adding register rs1 to the sign-extended 12-bit offset
void LB(i_type instruction, registers * banco, int8_t * memory){//VALIDAR
    printf("LB %d, %d(%d)",instruction.rd, instruction.imm, instruction.rs1);
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + instruction.imm;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, instruction.imm);

    int8_t data = memory[effectiveAddress];
    int8_t * rd = (int8_t *)getRegister(instruction.rd, banco);
    *rd = data;
}

// t2 = ENDERECO A SER ACESSADO;
// MEM[t2] ====>> AB CD

// LW t1, 1(t2)  ---> t1 = mem[t2+1] (2 bytes) , t1 = CD
// //LB t1, 0(t2)  ---> t1 = mem[t2+0] (byte) , t1 = D
// //LB t1, 1(t2)  ---> t1 = mem[t2+1] (byte) , t1 = C
// LB t1, 2(t2)  ---> t1 = mem[t2+2] (byte) , t1 = B
// LB t1, 3(t2)  ---> t1 = mem[t2+3] (byte) , t1 = A


//LH loads a 16-bit value from memory, then sign-extends to 32-bits before storing in rd.
void LH(i_type instruction, registers * banco, int16_t * memory){//VALIDAR
    printf("LH %d, %d(%d)",instruction.rd, instruction.imm, instruction.rs1); //ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + instruction.imm;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, instruction.imm);

    int16_t data = memory[effectiveAddress];
    int16_t * rd = (int16_t *)getRegister(instruction.rd, banco);
    *rd = data;
}

//The LW instruction loads a 32-bit value from memory into rd.
void LW(i_type instruction, registers * banco, int32_t *memory){//VALIDAR
    printf("LW %d, %d(%d)",instruction.rd, instruction.imm, instruction.rs1);//ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + instruction.imm;
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, instruction.imm);

    int32_t data = memory[effectiveAddress];
    int32_t * rd = getRegister(instruction.rd, banco);
    *rd = data;
}

//LBU loads a 8-bit value from memory but then zero extends to 32-bits before storing in rd.
void LBU(i_type instruction, registers * banco, int32_t *memory){//VALIDAR
    printf("LBU %d, %d(%d)",instruction.rd, instruction.imm, instruction.rs1);//ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + instruction.imm; 
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, instruction.imm);

    int32_t data = memory[effectiveAddress] & 0x000000FF;
    int32_t * rd = (int32_t *)getRegister(instruction.rd, banco);
    *rd = data;
}

//LHU loads a 16-bit value from memory but then zero extends to 32-bits before storing in rd
void LHU(i_type instruction, registers * banco, int32_t *memory){//VALIDAR
    printf("LHU %d, %d(%d)",instruction.rd, instruction.imm, instruction.rs1);//ok
    // Rs1 + Sign-extended 12-bit offset
    int32_t * rs1_value = getRegister(instruction.rs1, banco);
    int32_t effectiveAddress = *rs1_value + instruction.imm; 
    printf(">>> DEBUG >>> effectiveAddress (%d) = rs1 (%d) + imm (%d)\n\t", effectiveAddress, *rs1_value, instruction.imm);

    int32_t data = memory[effectiveAddress] & 0x0000FFFF;
    int32_t * rd = (int32_t *)getRegister(instruction.rd, banco);
    *rd = data;
}

void ADDI(i_type instruction, registers * banco){//OK
    printf("ADDI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    *rd = (*rs1) + instruction.imm;
}

//SLTI (set less than immediate) places the value 1 in register rd if register rs1 is less than the sign-extended immediate when both are treated as signed numbers, else 0 is written to rd.
void SLTI(i_type instruction, registers * banco){ //OK
    printf("SLTI x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    
    if((*rs1) < instruction.imm)
        (*rd) = 1;
    else 
        (*rd) = 0;
}

//SLTIU is similar but compares the values as unsigned numbers (i.e., the immediate is first sign-extended to XLEN bits then treated as an unsigned number). Note, SLTIU rd, rs1, 1 sets rd to 1 if rs1 equals zero, otherwise sets rd to 0 (assembler pseudo-op SEQZ rd, rs).
void SLTIU(i_type instruction, registers * banco){//OK
    printf("SLTIU x%d, x%d, x%d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);

    uint32_t rs1_u = (*rs1);
    int32_t ImmSE = instruction.imm;

    uint32_t ImmNS = ImmSE;

    if(rs1_u < ImmNS)
        (*rd) = 1;
    else 
        (*rd) = 0;
}

void XORI(i_type instruction, registers * banco){//OK
    printf("XORI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    *rd = (*rs1) ^ instruction.imm;
}

void ORI(i_type instruction, registers * banco){//OK
    printf("ORI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    *rd = (*rs1) | instruction.imm;
}

void ANDI(i_type instruction, registers * banco){//OK
    printf("ANDI x%d, x%d, %d",instruction.rd, instruction.rs1, instruction.imm);//ok
    int32_t* rd = getRegister(instruction.rd, banco);
    int32_t* rs1 = getRegister(instruction.rs1, banco);
    *rd = (*rs1) & instruction.imm;
}