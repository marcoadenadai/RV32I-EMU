#include "instructions.h"

//Verificar os Shifts (Ver se os operadores (<</>>) estão certo)
//note: arithmetic right shift '>>='
//Lógico -> completa com zero (Na direita ou na esquerda)
//Aritmético -> O  bit mais significativo é usado para completar (Na direita) (Extensão de sinal)

int32_t getImmB(uint8_t ImmA, uint8_t ImmB){ //OK 200%
    int32_t ret;
    int16_t aux_16;
    uint16_t bit12, bit11, bit10_5, bit4_0;
     
    bit12 = (0b01000000 & ImmB) >> 6;   // |12| <sign>  (Total: 1 bit)
    bit11 = (0b00000001 & ImmA) << 10;  // |11|         (Total: 1 bit)
    bit10_5 = (0b00111111 & ImmB) << 5; // [10:5]       (Total: 4 bits)
    bit4_0 = 0b0000000000011110 & ImmA; // [4:1]|0|     (Total: 5 bits)

    aux_16 = 0 | (bit12 << 11) | bit11 | bit10_5 | bit4_0; // Total (12 Bits)
    ret = aux_16; // POSITIVE VALUE (UNSIGNED)

    if(bit12 == 1)
        ret |= 0xFFFFF000;
    
    return ret; // SIGNED ( - : 1111, OR + : 0000) |12|11|[10:5]|[4:1]|0
}

int32_t getImmJ(int32_t Imm){ // TODO PRECISA FAZER / VALIDAR
    // imm[20|10:1|11|19:12]

    int32_t ret = 0b0;
    //int16_t aux_16;
    uint32_t bit20, bit10_1, bit11, bit19_12;

    // OS PRIMEIROS 8 BITS DO IMEDIATO EQUIVALEM AOS BITS 19:12 da Resposta
    bit19_12 =  (0b00000000000011111111 & Imm) << 12;             // ...[19:12]  (Total=8)
    // O BIT 9 DO IMEDIATO EQUIVALE AO BITS 11 da Resposta
    bit11 =     (0b00000000000100000000 & Imm) << 3;        // ...|11|[19:12]   (Total=9)
    // OS BITS 18:9 DO IMEDIATO EQUIVALEM AOS BITS 10:1 da Resposta
    bit10_1 =   (0b01111111111000000000 & Imm) >> 8;        // ..[10:1]|11|[19:12] (Total=19)
    // O BIT 19 DO IMEDIATO EQUIVALE AO BIT 20 da Resposta;
    bit20   =   (0b10000000000000000000 & Imm) << 1;        // ..|20|[10:1]|11|[19:12] (Total=20)

    ret = 0 | bit20 | bit10_1 | bit11 | bit19_12;           // Total (20 Bits)
    //ret = aux_16; // POSITIVE VALUE (UNSIGNED)

     if((bit20 >> 20) == 1)
         ret |= (int32_t) 0xFFF00000;
    
    return ret; // SIGNED ( - : 1111, OR + : 0000) [20|10:1|11|19:12]
}

int32_t getImmS(uint8_t Imm1, uint8_t Imm2){ //OK 100%
    //[11:5][4:0]
    int32_t ret;
    int16_t aux_16 = Imm2;
    aux_16 <<= 5;
    aux_16 |= Imm1;
    ret = aux_16;

    int16_t mask11 = 1 << 10;
    int16_t bit11 = (aux_16 & mask11) >> 10;

    if(bit11==1) // NEGATIVE VALUE
        ret |= 0xFFFFF000; //SIGNED

    return ret;
}

//Function returns the register address
int32_t * getRegister(uint8_t Reg, registers * banco){ // OK VALIDADO (ordem certa)
    switch(Reg){
        case 0:
            return ((int32_t*)&(banco->zero));
        case 1:
            return (&(banco->ra));
        case 2:
            return (&(banco->sp));
        case 3:
            return (&(banco->gp));
        case 4:
            return (&(banco->tp));
        case 5:
            return (&(banco->t0));
        case 6:
            return (&(banco->t1));
        case 7:
            return (&(banco->t2));
        case 8:
            return (&(banco->s0));
        case 9:
            return (&(banco->s1));
        case 10:
            return (&(banco->a0));
        case 11:
            return (&(banco->a1));
        case 12:
            return (&(banco->a2));
        case 13:
            return (&(banco->a3));
        case 14:
            return (&(banco->a4));
        case 15:
            return (&(banco->a5));
        case 16:
            return (&(banco->a6));
        case 17:
            return (&(banco->a7));
        case 18:
            return (&(banco->s2));
        case 19:
            return (&(banco->s3));
        case 20:
            return (&(banco->s4));
        case 21:
            return (&(banco->s5));
        case 22:
            return (&(banco->s6));
        case 23:
            return (&(banco->s7));
        case 24:
            return (&(banco->s8));
        case 25:
            return (&(banco->s9));
        case 26:
            return (&(banco->s10));
        case 27:
            return (&(banco->s11));
        case 28:
            return (&(banco->t3));
        case 29:
            return (&(banco->t4));
        case 30:
            return (&(banco->t5));
        case 31:
            return (&(banco->t6));
        default:
            printf("UNKOWN REG ID\n");
            return ((int32_t*)&(banco->zero));
    }
}