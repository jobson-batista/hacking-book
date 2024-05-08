#include <stdio.h>

int main() {
    /*
        É esperado um aviso do compilador, para exemplificar atribuições incompatíveis.
        Apesar do aviso, o programa é compilado mesmo assim.
    */
    int i;

    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = int_array; // char_pointer e int_pointer apontam para tipos
    int_pointer = char_array; // de dados incompatíveis.

    for(i=0; i < 5; i++) {
        printf("[integer pointer] Aponta para %p, que contém o char %c\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1; // Incrementa em 4 bytes o endereço de memória. Porque é um inteiro.
    }

    for(i=0; i < 5; i++) {
        printf("[char pointer] Aponta para %p, que contém o inteiro %d\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1; // Incrementa em 1 byte o endereço de memória.
    }

    return 0;
}