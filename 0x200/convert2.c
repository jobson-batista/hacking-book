#include <stdio.h>
#include <stdlib.h>

void usage(char *program_name) {
    printf("Uso: %s <mensagem> <# de vezes para repetir>\n", program_name);
    exit(1); // Incluso no stdlib.h
}

// O primeiro argumento ( argv[0] ) sempre é o nome do programa. 
int main(int argc, char *argv[]) {
    int i, count;

    // if (argc < 3) { // Se tiver menos de 3 argumentos ele exitbe a mensagem de uso e sai.
    //     usage(argv[0]);
    // }
    
    count = atoi(argv[2]);
    printf("Repetindo %d vezes...\n", count);

    for(i=0; i < count; i++) {
        printf("%3d - %s\n", i, argv[1]); //Imprime o primeiro argumento (mensagem)
    }
}