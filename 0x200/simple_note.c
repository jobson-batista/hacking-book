#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

/*
    Manipular arquivos em cada lib:
    # stdio.h       # unistd.h
    - fopen         - open
    - fclose        - close
    - fwrite        - write
*/

void usage(char *prog_name, char *file_name) {
    printf("Uso: %s <dados a serem adicionados em %s>\n", prog_name, file_name);
    exit(0);
}

void fatal(char*);  // Função que retorna erros criticos
void *ec_malloc(unsigned int); //Um wrapper malloc() de verificaçao de erros

int main(int argc, char *argv[]) {
    int file_descriptor;
    char *buffer, *data_file;

    buffer = (char *) ec_malloc(100);
    data_file = (char *) ec_malloc(20);
    strcpy(data_file, "output/notes.txt");

    if(argc < 2) usage(argv[0], data_file); // Se não há parametros de linha de comando, exibe uma mensagem e sai

    strcpy(buffer, argv[1]); // Copia o argumento para o buffer
    
    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] data_file @ %p: \'%s\'\n", data_file, data_file);

    strncat(buffer, "\n", 1); // Adiciona uma nova linha no final

    // Abrindo o arquivo
    file_descriptor = open(data_file, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);

    if(file_descriptor == -1) {
        fatal("em main() ao abrir o arquivo!");
    }
    // Descriptor do arquivo ou File Descriptor é um número identificador 
    // do arquivo dentre os arquivos abertos, como se fosse o ISBN de um livro.
    printf("[DEBUG] O descritor do arquivo é %d\n",file_descriptor); 
    
    // Salvando dados
    if(write(file_descriptor, buffer, strlen(buffer)) == -1) {
        fatal("em main() ao definir o buffer para o arquivo.");
    } 

    // Fechando o arquivo
    if(close(file_descriptor) == -1) {
        fatal("em main() ao fechar o arquivo.");
    }

    printf("Anotação foi salva!\n");
    free(buffer);
    free(data_file);
}

// Uma função que exibe uma mensagem de erro e sai
void fatal(char *message) {
    char error_message[100];

    strcpy(error_message, "[!!] Fatal Error! ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}   

// Uma função wrapper malloc() de verificação de erros
void *ec_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL) fatal("em ec_malloc() na alocação de memória.");
    return ptr;
}