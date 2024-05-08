#include <stdio.h>

int main() {
    
    int i;

    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    char_pointer = (char *) int_array; // char_pointer e int_pointer são
    int_pointer = (int *) char_array; // forçados a serem do tipo char e int respectivamente

    for(i=0; i < 5; i++) {
        printf("[integer pointer] Aponta para %p, que contém o char %c\n", int_pointer, *int_pointer);
        int_pointer =  (int *) ((char *) int_pointer + 1); // Incrementa em 1 bytes o endereço de memória e depois muda o tipo para int.
    }

    for(i=0; i < 5; i++) {
        printf("[char pointer] Aponta para %p, que contém o inteiro %d\n", char_pointer, *char_pointer);
        char_pointer = (char *) ((int *) char_pointer + 1); // Incrementa em 4 byte o endereço de memória e muda o tipo para char.
    }

    return 0;
}