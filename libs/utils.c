#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void printBin (unsigned n) {
    if (n > 1)
        printBin(n >> 1);
    printf("%d", n & 1);
}

void dumpMem(void * memory, unsigned size, const char * fileName) {
    FILE * fp = fopen(fileName, "w");
    uint8_t * ptr = (uint8_t*) memory;
    if(fp) {
        //fprintf(fp, "");
        fprintf(fp, "- Adrress ----- Memory Data -------------------------------------------------------------------------------------------\n                03 02 01 00  07 06 05 04  0B 0A 09 08  0F 0E 0D 0C  13 12 11 10  17 16 15 14  1B 1A 19 18  1F 1E 1D 1C\n-----------------------------------------------------------------------------------------------------------------------");
        for(unsigned i=0;i<size;i+=4){
            if(i%32 == 0)
                fprintf(fp, "\n(0x%06x)  \t", i);

            fprintf(fp, "%02X %02X %02X %02X  ",  ptr[i+3], ptr[i+2], ptr[i+1], ptr[i]);
        }
        fprintf(fp, "\n");
        fclose(fp);
    }
}

void dumpRegisters(registers banco_reg){
    int i=0;
    printf("\n╔═ Registers Dump ═══════════╗\n");
    printf("║                            ║\n");   
    printf("║       hex      dec    n    ║\n");
    printf("║ zero: 0x%04x   %04d   x%01d   ║\n", banco_reg.zero, banco_reg.zero, i++);
    printf("║ ra:   0x%04x   %04d   x%01d   ║\n", banco_reg.ra, banco_reg.ra, i++);
    printf("║ sp:   0x%04x   %04d   x%01d   ║\n", banco_reg.sp, banco_reg.sp, i++);
    printf("║ gp:   0x%04x   %04d   x%01d   ║\n", banco_reg.gp, banco_reg.gp, i++);
    printf("║ tp:   0x%04x   %04d   x%01d   ║\n", banco_reg.tp, banco_reg.tp, i++);
    printf("║ t0:   0x%04x   %04d   x%01d   ║\n", banco_reg.t0, banco_reg.t0, i++);
    printf("║ t1:   0x%04x   %04d   x%01d   ║\n", banco_reg.t1, banco_reg.t1, i++);
    printf("║ t2:   0x%04x   %04d   x%01d   ║\n", banco_reg.t2, banco_reg.t2, i++);
    printf("║ s0:   0x%04x   %04d   x%01d   ║\n", banco_reg.s0, banco_reg.s0, i++);
    printf("║ s1:   0x%04x   %04d   x%01d   ║\n", banco_reg.s1, banco_reg.s1, i++);
    printf("║ a0:   0x%04x   %04d   x%01d  ║\n", banco_reg.a0, banco_reg.a0, i++);
    printf("║ a1:   0x%04x   %04d   x%01d  ║\n", banco_reg.a1, banco_reg.a1, i++);
    printf("║ a2:   0x%04x   %04d   x%01d  ║\n", banco_reg.a2, banco_reg.a2, i++);
    printf("║ a3:   0x%04x   %04d   x%01d  ║\n", banco_reg.a3, banco_reg.a3, i++);
    printf("║ a4:   0x%04x   %04d   x%01d  ║\n", banco_reg.a4, banco_reg.a4, i++);
    printf("║ a5:   0x%04x   %04d   x%01d  ║\n", banco_reg.a5, banco_reg.a5, i++);
    printf("║ a6:   0x%04x   %04d   x%01d  ║\n", banco_reg.a6, banco_reg.a6, i++);
    printf("║ a7:   0x%04x   %04d   x%01d  ║\n", banco_reg.a7, banco_reg.a7, i++);
    printf("║ s2:   0x%04x   %04d   x%01d  ║\n", banco_reg.s2, banco_reg.s2, i++);
    printf("║ s3:   0x%04x   %04d   x%01d  ║\n", banco_reg.s3, banco_reg.s3, i++);
    printf("║ s4:   0x%04x   %04d   x%01d  ║\n", banco_reg.s4, banco_reg.s4, i++);
    printf("║ s5:   0x%04x   %04d   x%01d  ║\n", banco_reg.s5, banco_reg.s5, i++);
    printf("║ s6:   0x%04x   %04d   x%01d  ║\n", banco_reg.s6, banco_reg.s6, i++);
    printf("║ s7:   0x%04x   %04d   x%01d  ║\n", banco_reg.s7, banco_reg.s7, i++);
    printf("║ s8:   0x%04x   %04d   x%01d  ║\n", banco_reg.s8, banco_reg.s8, i++);
    printf("║ s9:   0x%04x   %04d   x%01d  ║\n", banco_reg.s9, banco_reg.s9, i++);
    printf("║ s10:  0x%04x   %04d   x%01d  ║\n", banco_reg.s10, banco_reg.s10, i++);
    printf("║ s11:  0x%04x   %04d   x%01d  ║\n", banco_reg.s11, banco_reg.s11, i++);
    printf("║ t3:   0x%04x   %04d   x%01d  ║\n", banco_reg.t3, banco_reg.t3, i++);
    printf("║ t4:   0x%04x   %04d   x%01d  ║\n", banco_reg.t4, banco_reg.t4, i++);
    printf("║ t5:   0x%04x   %04d   x%01d  ║\n", banco_reg.t5, banco_reg.t5, i++);
    printf("║ t6:   0x%04x   %04d   x%01d  ║\n", banco_reg.t6, banco_reg.t6, i++);
    printf("╚════════════════════════════╝\n\n");
}

unsigned long loadInstructions(const char * filename, gen_type * instructList) {
    int count = 0;
    uint32_t aux;
    FILE * fp = fopen(filename, "rb");

    if(fp) {
        while( fread( (uint32_t*)&aux, sizeof(aux), 1, fp ) == 1 ) {
            instructList[count] = aux;
            count++;
        }
        fclose(fp);
    }
    return count; // Return total instructions loaded
}