#include <stdio.h>

int main() {
    printf("O tipo de dado 'int' tem\t\t %lu bytes\n", sizeof(unsigned int));
    printf("O tipo de dado 'unsigned int' tem\t %lu bytes\n", sizeof(unsigned int));
    printf("O tipo de dado 'short int tem\t\t %lu bytes\n", sizeof(short int));
    printf("O tipo de dado 'long int' tem\t\t %lu bytes\n", sizeof(long int));
    printf("O tipo de dado 'long long int' tem\t %lu bytes\n", sizeof(long long int));
    printf("O tipo de dado 'float' tem\t\t %lu bytes\n", sizeof(float));
    printf("O tipo de dado 'char' tem\t\t %lu bytes\n", sizeof(char));
}