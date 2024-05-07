#include <stdio.h>
#include <string.h>

int main() {
    char string[10];
    int A = -73;
    unsigned int B = 31337;

    strcpy(string, "sample");

    printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
    printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
    printf("[Field width on B] 3: '%3u', 10: '%10u', 08: '%08u', 06: '%06u'\n", B, B, B, B);
    printf("[string] %s Address %p\n", string, (void *)string);

    printf("O endereço da variável A: %p\n", &A);
}