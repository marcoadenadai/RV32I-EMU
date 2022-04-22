#pragma once
#include <stdio.h>
#include <stdint.h>

#define MASK_OPCODE 0b00000000000000000000000001111111
#define MASK_FUNC3  0b00000000000000000111000000000000
#define MASK_FUNC7  0b11111110000000000000000000000000

#pragma pack(push,1) // Alinha o programa de 1 byte em 1 byte

typedef uint32_t gen_type;

// R-TYPE Instructions Structure
typedef struct {
    unsigned opcode : 7;
    unsigned rd : 5;
    unsigned func3 : 3;
    unsigned rs1 : 5;
    unsigned rs2 : 5;
    unsigned func7 : 7;
} r_type;
// I-TYPE Instructions Structure
typedef struct {
    unsigned opcode : 7;
    unsigned rd : 5;
    unsigned func3 : 3;
    unsigned rs1 : 5;
    int imm : 12;
} i_type;
// S-TYPE Instructions Structure
typedef struct {
    unsigned opcode : 7;
    unsigned imm1 : 5;
    unsigned func3 : 3;
    unsigned rs1 : 5;
    unsigned rs2 : 5;
    unsigned imm2 : 7;
} s_type;
// B-TYPE Instructions Structure
typedef s_type b_type;
// U-TYPE Instructions Structure
typedef struct {
    unsigned opcode : 7;
    unsigned rd : 5;
    unsigned imm : 20;
} u_type;
// J-TYPE Instructions Structure
typedef u_type j_type;


// Banco de registradores
typedef struct regs{
    const int32_t zero;
    int32_t ra; // Return address
    int32_t sp; // Stack pointer
    int32_t gp; // Global pointer
    int32_t tp; // Thread pointer
    int32_t t0; // Temporary register
    int32_t t1; // Temporary register
    int32_t t2; // Temporary register
    int32_t s0; // Saved register
    int32_t s1; // Saved register
    int32_t a0; // Arguments register
    int32_t a1; // Arguments register
    int32_t a2; // Arguments register
    int32_t a3; // Arguments register
    int32_t a4; // Arguments register
    int32_t a5; // Arguments register
    int32_t a6; // Arguments register
    int32_t a7; // Arguments register
    int32_t s2; // Saved register
    int32_t s3; // Saved register
    int32_t s4; // Saved register
    int32_t s5; // Saved register
    int32_t s6; // Saved register
    int32_t s7; // Saved register
    int32_t s8; // Saved register
    int32_t s9; // Saved register
    int32_t s10; // Saved register
    int32_t s11; // Saved register
    int32_t t3; // Temporary register
    int32_t t4; // Temporary register
    int32_t t5; // Temporary register
    int32_t t6; // Temporary register
}registers;

#pragma pack(pop) // Volta ao alinhamento normal para não perder performance
// Utils Translation functions
int32_t getImmB(uint8_t ImmA, uint8_t ImmB);
int32_t getImmJ(int32_t Imm);
int32_t getImmS(uint8_t Imm1, uint8_t Imm2);
int32_t * getRegister(uint8_t Reg, registers * banco);