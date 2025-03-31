#include "validator.h"
#include "hasher.h"
#include "array.h"

int validate_signature(byte* payload, const int payload_len, byte sign[4]) {
    byte hash[4];
    compute_hash(payload, payload_len, hash);
    for(int i = 0; i < 4; i++) {
        if (hash[i] != sign[i]) {
            return 0;
        } 
    }
    return 1;
}

int validate_id(byte id[4]) {
    return 1;
}

int validate_activation_key(byte a_key[16], byte* private_key, int private_key_len) {
    byte sign[4];
    int result = 1;
    for (int cur_round_num = 0; cur_round_num < 3; cur_round_num++) {
        for (int i = 0; i < 4; i++) {
            sign[i] = a_key[i + (12 - 4 * cur_round_num)];
        }
        byte* round;
        int round_len;
        merge_arrays(a_key, 12 - 4 * cur_round_num, private_key, private_key_len, &round, &round_len);
        result = result && validate_signature(round, round_len, sign);
        free(round);
    }
    result = result && validate_id(a_key);
    return result;
}