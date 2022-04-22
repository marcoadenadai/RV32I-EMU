#include "j_type.h"

//The jump and link (JAL) instruction uses the J-type format, where the 

//J-immediate encodes a signed offset in multiples of 2 bytes. 

void JAL(j_type instruction, registers * banco, int * PC){ //OK
    uint32_t * rd = getRegister(instruction.rd, banco);
    int32_t Imm = getImmJ(instruction.imm); // The offset is sign-extended
    printf("JAL x%d, %d",instruction.rd, Imm); //ok


    // Endereco Oficial = ((Imm << 1) + *PC)

    //int32_t NextAddr = (*PC) + (Imm/4);
    //NextAddr -= 1; // Subtract 1 because next step will always add 1 to (FOR condition in Main.c)

    //  Our PC is incremented 1 by 1
    (*rd) = (*PC + 1) * 4; //JAL stores the address of the instruction following the jump (pc+4) into register rd.

    // The sign-extended offset is added to the pc to form the jump target address. 
    (*PC) = *PC + (Imm >> 2) - 1;
}