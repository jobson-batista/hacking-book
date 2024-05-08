#include <stdio.h>

int main() {
    
    int i;

    char char_array[5] = {'a','b','c','d','e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    unsigned int hacky_non_pointer;

    hacky_non_pointer = (unsigned int) int_array;

    for(i=0; i < 5; i++) {
        printf("[integer pointer] Aponta para %u, que contém o inteiro %d\n", hacky_non_pointer, *((int *) hacky_non_pointer));
        hacky_non_pointer = hacky_non_pointer + sizeof(char);
    }

    hacky_non_pointer = (unsigned int) char_array;

    for(i=0; i < 5; i++) {
        printf("[char pointer] Aponta para %u, que contém o char %c\n", hacky_non_pointer, *((char *) hacky_non_pointer));
        hacky_non_pointer = hacky_non_pointer + sizeof(int);
    }

    return 0;
}