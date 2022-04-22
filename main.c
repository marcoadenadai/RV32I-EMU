#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "libs/instructions.h"
#include "libs/decode.h"
#include "libs/utils.h"

#define EPROM_SIZE 5 * 1024 * 1024 / 4  // 5 MB * 1024 KB * 1024 bytes / 4 bytes ( instruction size )
#define RAM_SIZE 1 * 1024 * 1024 / 4    // 1 MB * 1024 KB * 1024 bytes / 4 byteS ( word size )

int main(){
    // Banco de registradores
    registers banco_reg;
    memset(&banco_reg, 0x00, sizeof(registers));
    // Memoria de Instrucao (EPROM)
    gen_type instructionsList[EPROM_SIZE];
    // Memoria de Dados (RAM)
    int32_t memory[RAM_SIZE];
    memset(memory, 0x00, sizeof(memory));
    
    char dump_file[] = "memdump.txt";
    char bin_file[] = "sample4J.bin";//"fibo.bin";//"sample3.bin";

    unsigned long totalInstructions = loadInstructions(bin_file, instructionsList);

    printf("[RV32-I Emulator] Successfully Loaded \"%s\"\n", bin_file);
    printf("[RV32-I Emulator] EPROM_SIZE(%03.2f MB); RAM_SIZE(%03.2f MB);\n\n", \
    (float)sizeof(instructionsList)/1024/1024, (float)sizeof(memory)/1024/1024);

    printf("Run Debug (%ld total instructions):\n\n", totalInstructions);

    printf(" line    assembly\t\thex\n\n");
    int pc;
    for(pc=0; pc<totalInstructions; pc++) {

        uint32_t ins = instructionsList[pc];
        printf(" %04d    ",pc);
        decode(ins, &banco_reg, memory, &pc);
        printf("\t\t(0x%04x)\n\n", ins);
    }

    printf("Execution End (pc=%04d)\n",pc);
    printf("\n================================================================\n");
    dumpRegisters(banco_reg);
    dumpMem(memory, RAM_SIZE, dump_file);

    return 0;
}