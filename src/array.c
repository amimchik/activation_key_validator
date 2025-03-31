#include "array.h"

void merge_arrays(byte* arr1, const int arr1l, byte* arr2, const int arr2l, byte** res, int* resl) {
    byte* final = (byte*)malloc(sizeof(byte) * (arr1l + arr2l));
    *resl = arr1l + arr2l;
    int i = 0;
    for (; i < arr1l; i++) {
        final[i] = arr1[i];
    }
    for (int x = 0; x < arr2l; i++, x++) {
        final[i] = arr2[x];
    }
    *res = final;
}
