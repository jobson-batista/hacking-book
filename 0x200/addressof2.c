#include <stdio.h>

int main() {

    int int_var = 5;
    int *int_ptr;

    int_ptr = &int_var; // Passa o endereço de int_var para int_ptr

    printf("int_ptr = %p\n", int_ptr);
    printf("&int_ptr = %p\n", &int_ptr);
    printf("*int_ptr = 0x%08x\n\n", *int_ptr);

    printf("int_var está alocado em %p e possui o valor %d\n", &int_var, int_var);
    printf("int_ptr está alocado em %p, possui o valor %p e aponta para %d\n\n",&int_ptr, int_ptr, *int_ptr);
}