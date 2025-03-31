#include "strtohexconverter.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

sbyte hex_c_to_byte(char c) {
    sbyte result = -1;

    if (isdigit(c)) {
        result = c - '0';
    } else {
        if (c >= 'a' && c <= 'f') {
            result = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            result = c - 'A' + 10;
        }
    }

    return result;
} 

void convert_to_hex(char* input, byte** output, int* output_l) {
    byte* output_buffer = (byte*)malloc(sizeof(byte) * strlen(input));
    for(int text_i = 0, arr_i = 0; text_i < strlen(input); text_i++) {
        sbyte a = hex_c_to_byte(input[text_i * 2]);
        sbyte b = hex_c_to_byte(input[text_i * 2 + 1]);
        if (b == -1 || a == -1) {
            continue;
        }
        output_buffer[arr_i] = (byte)a * 16 + (byte)b;
        arr_i++;
        *output_l = arr_i;
    }
    *output = output_buffer;
}
