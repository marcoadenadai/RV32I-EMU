# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g

# the build target executable:
TARGET = main

DEPS = libs/utils.c libs/instructions/r_type.c libs/instructions/i_type.c libs/instructions/s_type.c libs/instructions/b_type.c libs/instructions/u_type.c libs/instructions/j_type.c libs/decode.c libs/instructions.c

all: clean $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c $(DEPS) -o $(TARGET)

TMP = riscv64-linux-gnu-gcc -march=rv64g -static -nostdlib -nostartfiles sample3.s && riscv64-linux-gnu-objcopy -O binary --only-section=.text a.out prog.bin && rm a.out && mv prog.bin ../../sample3.bin

# riscv64-linux-gnu-gcc -march=rv64g -static -nostdlib -nostartfiles sample3.s && riscv64-linux-gnu-objcopy -O binary --only-section=.text a.out prog.bin && rm a.out && mv prog.bin ../../sample3.bin

clean:
	$(RM) $(TARGET)