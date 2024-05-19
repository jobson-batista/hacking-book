#include <stdio.h>

int main() {
    int i, bit_a, bit_b;
    printf("bitwise operador OR |\n");
    for(i=0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Obtém o segundo bit.
        bit_b = (i & 1); // Obtém o primeiro bit.
        printf("%d | %d = %d\n",bit_a, bit_b, bit_a | bit_b);
    }
    printf("\nbitwise operador AND &\n");
    for(i=0; i < 4; i++) {
        bit_a = (i & 2) / 2; // Obtém o segundo bit.
        bit_b = (i & 1); // Obtém o primeiro bit.
        printf("%d & %d = %d\n",bit_a, bit_b, bit_a & bit_b);
    }
}