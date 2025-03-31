#include "key_generator.h"


void generate_id(int seed, byte id[4]) {
    compute_hash((byte*)&seed, sizeof(int), id); 
}

void make_sign(byte* payload, const int payload_len, byte* priv_key, const int priv_key_len, byte sign[4]) {
    byte* merged_payload;
    int merged_payload_len;
    merge_arrays(payload, payload_len, priv_key, priv_key_len, &merged_payload, &merged_payload_len);
    
    compute_hash(merged_payload, merged_payload_len, sign);
}

void generate_key(byte* priv_key, const int priv_key_len, int seed, byte key[16]) {
    byte id[4];
    generate_id(seed, id);
    for (int i = 0; i < 4; i++) {
        key[i] = id[i];
    }
    for (int round = 0; round < 3; round++) {
        make_sign(key, round * 4 + 4, priv_key, priv_key_len, key + round * 4 + 4);
    }
}
