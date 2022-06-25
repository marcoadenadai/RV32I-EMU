# RISCV-Emulator




Compilando o Emumlador:
```
gcc main.c libs/instructions.c -o main

gcc main.c libs/instructions/r_type.c libs/instructions/i_type.c libs/instructions/s_type.c libs/instructions/b_type.c libs/instructions/u_type.c libs/instructions/j_type.c libs/decode.c libs/instructions.c -o main

```

Compilando Binario ASM:
```
riscv64-linux-gnu-gcc -march=rv64g -static -nostdlib -nostartfiles fibo.s && \
riscv64-linux-gnu-objcopy -O binary --only-section=.text a.out prog.bin && \
rm a.out && mv prog.bin ../../fibo.bin
```

---

Note: To be improved.
