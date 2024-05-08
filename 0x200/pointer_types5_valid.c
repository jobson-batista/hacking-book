#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main( void ) {
    enum { N = 5 };
    char char_array[N] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[N] = {1, 2, 3, 4, 5};

    uintptr_t hacky_nonpointer;

    hacky_nonpointer = ( uintptr_t )( void * )char_array;

    for ( int i = 0; i < N; i++ ) { // iterate through the int array with the int_pointer
        printf("[hacky_nonpointer] points to %" PRIuPTR ", which contains the char '%c'\n",
            hacky_nonpointer, *( char * )( void * )hacky_nonpointer );
        hacky_nonpointer = hacky_nonpointer + sizeof(char);
    }

    hacky_nonpointer = ( uintptr_t )( void * )int_array;
    
    for ( int i = 0; i < N; i++ ) { // iterate through the int array with the int_pointer
        printf("[hacky_nonpointer] points to %" PRIuPTR ", which contains the integer %d\n",
            hacky_nonpointer, *( int * )( void * )hacky_nonpointer );
        hacky_nonpointer = hacky_nonpointer + sizeof(int);
    }
}