#include <stdio.h>

#include "defines.h"
#include "hasher.h"
#include "validator.h"
#include "key_generator.h"
#include "strtohexconverter.h"

byte priv_key[] = { 43, 42, 1, 122, 43, 11, 86, 54 };

void to_hex(byte v, char c[2]) {
    if (v / 16 < 10) {
        c[0] = v / 16 + '0';
    } else {
        c[0] = v / 16 - 10 + 'a';
    }
    if (v % 16 < 10) {
        c[1] = v % 16 + '0';
    } else {
        c[1] = v % 16  - 10 + 'a';
    }
}

void print_hex(byte* arr, const int length) {
    char buffer[3];
    buffer[2] = '\0';
    for (int i = 0; i < length; i++) {
        to_hex(arr[i], buffer);
        printf("%s", buffer);
    }
}

void print_arr(byte* arr, const int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", (byte)(arr[i]));
    }
    printf("\n");
}


int main(int argc, const char* const argv[]) {
    while (1) {
        printf("\nWelcome to my program!\n1. Generate activation key\n2. Enter activation key\n3. Exit\nChoose an option: ");
        int choose = 0;
        scanf("%d", &choose);
        while (getchar() != '\n');
        if (choose == 1) {
            int seed = 0;
            byte key[16];
            printf("Enter seed: ");
            scanf("%d", &seed);
            while (getchar() != '\n');
            generate_key(priv_key, sizeof(priv_key), seed, key);
            print_hex(key, 16);
            printf("\n");
        } else if (choose == 2) {
            char code_str[100];
            printf("Enter activation key: ");
            fgets(code_str, sizeof(code_str), stdin);
            printf("\n");
            byte* code;
            int size = 0;
            convert_to_hex(code_str, &code, &size);
            if (code && size == 16) {
               if (validate_activation_key(code, priv_key, sizeof(priv_key))) {
                    printf("Welcome back!\n");
                } else {
                    printf("Incorrect code!\n");
                }
            } else {
                printf("Incorrect code!\n"); 
            }
            printf("\n"); 
            free(code);
        } else {
            break;
        }
    }
    return 0;
}
