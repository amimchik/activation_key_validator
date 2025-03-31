#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

#include "hasher.h"
#include "validator.h"
#include "defines.h"

void generate_id(int seed, byte id[4]);
void generate_key(byte* private_key, const int private_key_len, int seed, byte key[16]);

#endif
