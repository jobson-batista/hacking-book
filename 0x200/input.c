#include <stdio.h>
#include <string.h>

int main() {

    char message[14];
    int count, i;

    strcpy(message, "Hello, World!");

    printf("Repetir quantas vezes? ");
    scanf("%d", &count);

    for(i=0; i< count; i++) {
        printf("%3d - %s\n", i, message);
    }

    printf("O endereço de 'message' é %p e possui o valor %s\n", (void *)message, message);
}