.text
.global _start; _start:

derek:
    addi t1, x0, 1
    beq x0, x0, main

xxx:
    addi t1, x0, 2
    addi t2, x0, 3
    bge t2, t1, fim

main:
    addi t2, x0, 3
    addi t2, x0, 4
    addi t3, x0, 5
    bge t3, t2, xxx

fim: