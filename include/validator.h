#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "defines.h"
#include "array.h"

int validate_activation_key(byte a_key[16], byte* private_key, int private_key_len);

int validate_signature(byte* payload, const int payload_len, byte sign[4]);

#endif
