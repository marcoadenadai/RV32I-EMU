#include "decode.h" 

void decode(gen_type instruct, registers * banco_reg, int32_t * memory, int *PC){
    uint32_t opcode, func3, func7;


    opcode = instruct & MASK_OPCODE;
    func3 = instruct & MASK_FUNC3;
    func3 >>= 12;
    func7 = instruct & MASK_FUNC7;
    func7 >>= 25;

    switch(opcode)
    {
    // R TYPE -----------------------------------------------------------------------------------
        case 0b0110011:
            switch(func3)
            {
                case 0b0000:
                    if(func7 == 0) 
                        //ADD
                        ADD(* (r_type *) &instruct, banco_reg);
                    else
                        SUB(* (r_type *) &instruct, banco_reg);
                        //SUB
                break;
                case 0b0001:
                    SLL(* (r_type *) &instruct, banco_reg);
                    // SLL
                break;
                case 0b0010:
                    SLT(* (r_type *) &instruct, banco_reg);
                    // SLT
                break;
                case 0b0011:
                    SLTU(* (r_type *) &instruct, banco_reg);
                    // SLTU
                break;
                case 0b0100:
                    XOR(* (r_type *) &instruct, banco_reg);
                    // XOR
                break;
                case 0b0101:
                    if(func7 == 0)
                        SRL(* (r_type *) &instruct, banco_reg);
                        //SRL
                    else
                        SRA(* (r_type *) &instruct, banco_reg);
                        //SRA
                break;
                case 0b0110:
                    OR(* (r_type *) &instruct, banco_reg);
                    // OR
                break;
                case 0b0111:
                    AND(* (r_type *) &instruct, banco_reg);
                    // AND
                break;
                default:
                    printf("UNKNOWN INSTRUCTION\n");
            }
        break;
    // I TYPE -----------------------------------------------------------------------------------
        case 0b1100111:
            JALR(* (i_type *) &instruct, banco_reg, (*PC));
            // JALR
        break;
        case 0b0000011:
            switch(func3)
            {
                case 0b000:
                    LB(* (i_type *) &instruct, banco_reg, (int8_t*)memory);
                    // LB
                break;
                case 0b001:
                    LH(* (i_type *) &instruct, banco_reg, (int16_t*)memory);
                    // LH
                break;
                case 0b010:
                    LW(* (i_type *) &instruct, banco_reg, (int32_t*)memory);
                    // LW
                break;
                case 0b100:
                    LBU(* (i_type *) &instruct, banco_reg, memory);
                    // LBU
                break;
                case 0b101:
                    LHU(* (i_type *) &instruct, banco_reg, memory);
                    // LHU
                break;
                default:
                    printf("UNKNOWN INSTRUCTION\n");
            }
        break;
        case 0b0010011:
            switch(func3)
            {
                case 0b000:
                    ADDI(* (i_type *) &instruct, banco_reg);
                    // ADDI
                break;
                case 0b010:
                    SLTI(* (i_type *) &instruct, banco_reg);
                    // SLTI
                break;
                case 0b011:
                    SLTIU(* (i_type *) &instruct, banco_reg);
                    // SLTIU
                break;
                case 0b100:
                    XORI(* (i_type *) &instruct, banco_reg);
                    // XORI
                break;
                case 0b110:
                    ORI(* (i_type *) &instruct, banco_reg);
                    // ORI
                break;
                case 0b111:
                    ANDI(* (i_type *) &instruct, banco_reg);
                    // ANDI
                break;
                case 0b001:
                    SLLI(* (r_type *) &instruct, banco_reg);
                    // SLLI
                break;
                case 0b101:
                    if(func7 == 0){
                        SRLI(* (r_type *) &instruct, banco_reg);
                        printf("if do srl");
                        //SRL
                    }
                    else{
                        SRAI(* (r_type *) &instruct, banco_reg);
                        printf("if do srai");
                        //SRAI
                    }
                break;

            }
        break;
    // S TYPE -----------------------------------------------------------------------------------
        case 0b0100011:
            switch(func3)
            {
                case 0b000:
                    SB(* (s_type *) &instruct, banco_reg, (int8_t*)memory);
                    // SB
                break;
                case 0b001:
                    SH(* (s_type *) &instruct, banco_reg, (int16_t*)memory);
                    // SH
                break;
                case 0b010:
                    SW(* (s_type *) &instruct, banco_reg, (int32_t*)memory);
                    // SW
                break;
                default:
                    printf("UNKNOWN INSTRUCTION\n");
            }
        break;
    // B TYPE -----------------------------------------------------------------------------------
        case 0b1100011:
            switch(func3)
            {
                case 0b000:
                    BEQ(* (b_type *) &instruct, banco_reg, PC);
                    // BEQ
                break;
                case 0b001:
                    BNE(* (b_type *) &instruct, banco_reg, PC);
                    // BNE
                break;
                case 0b100:
                    BLT(* (b_type *) &instruct, banco_reg, PC);
                    // BLT
                break;
                case 0b101:
                    BGE(* (b_type *) &instruct, banco_reg, PC);
                    // BGE
                break;
                case 0b110:
                    BLTU(* (b_type *) &instruct, banco_reg, PC);
                    // BLTU
                break;
                case 0b111:
                    BGEU(* (b_type *) &instruct, banco_reg, PC);
                    // BGEU
                break;
                default:
                    printf("UNKOWN B INSTRUCTION\n");
            }
        break;
    // U TYPE -----------------------------------------------------------------------------------
        case 0b0011011:
            LUI(* (u_type *) &instruct, banco_reg);
            // LUI
        break;
        case 0b0010111:
            AUIPC(* (u_type *) &instruct, banco_reg, (*PC));
            // AUIPC
        break;
    // J TYPE -----------------------------------------------------------------------------------
        case 0b1101111:
            JAL(* (j_type *) &instruct, banco_reg, PC);
            // JAL
        break;
        default:
            printf("UNKNOWN OPCODE\n");
    }
}