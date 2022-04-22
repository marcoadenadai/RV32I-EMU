.text
inicio:
    addi x11,zero,0
    addi x10,zero,10
    jal x1, saltou

buraco:
    addi x10,zero,20
    addi a3, zero, 7
    beq  a4, a3, fim


saltou:
    addi x10,zero,30
    addi x10,zero,31
    addi x10,zero,32
    addi x10,zero,33
    addi x10,zero,34

saltou2:
    addi x10,zero,35
    addi x10,zero,36
    addi a4,zero, 7
    jal  x1,buraco
fim:

