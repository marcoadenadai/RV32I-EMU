#pragma once
#include <stdio.h>
#include <stdint.h>
#include "instructions.h"
#include "instructions/r_type.h"
#include "instructions/i_type.h"
#include "instructions/s_type.h"
#include "instructions/b_type.h"
#include "instructions/u_type.h"
#include "instructions/j_type.h"

void decode(gen_type instruct, registers * banco_reg, int32_t * memory, int *PC);
