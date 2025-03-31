#include "hasher.h"

void compute_hash(byte* arr, const int length, byte output[4]) {
    int n = 134;
    int hash = n;
    for(int i = 0; i < length; i++) {
        hash += (int)arr[i];
        hash *= n;
    }
    for(int i = 0; i < 4; i++) {
        output[i] = ((byte*)&hash)[i];
    }
}
