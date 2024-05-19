#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *error_checked_malloc(unsigned int);

int main(int argc, char *argv[]) {
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if(argc < 2) {
        mem_size = 50;
    } else {
        mem_size = atoi(argv[1]);
    }

    printf("\t[+] Alocando %d bytes no heap da memória para char_ptr\n", mem_size);
    char_ptr = (char *) error_checked_malloc(mem_size); // Alocando memória estática

    strcpy(char_ptr, "Esta memória está localizada no heap.");
    printf("char_ptr (%p) --> '%s'\n",char_ptr, char_ptr);

    printf("\t[+] Alocando 12 bytes no heap da memória para int_ptr\n");
    int_ptr = (int *) error_checked_malloc(12); // Memória estática alocada novamente 

    *int_ptr = 31337; // Coloca o valor 31337 no endereço apontado por int_ptr.
    printf("int_ptr (%p) --> %d\n",int_ptr, *int_ptr);

    printf("\t[-] Liberando char_ptr do heap da memória...\n");
    free(char_ptr); // Libera a memória estática

    printf("\t[+] Alocando mais 15 bytes para char_ptr.\n");
    char_ptr = (char *) error_checked_malloc(15); // Aloca mais memória heap

    strcpy(char_ptr, "Nova Memória!");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    printf("\t[-] Liberando int_ptr do heap da memória...\n");
    free(int_ptr);
    printf("\t[-] Liberando char_ptr do heap da memória...\n");
    free(char_ptr);
}

void *error_checked_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Erro: Não foi possível alocar no heap.");
        exit(-1); // Indica que o programa encerrou com erro.
    }
    return ptr;
}