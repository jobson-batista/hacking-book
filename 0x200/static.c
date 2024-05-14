#include <stdio.h>

void function() {
    int var = 5; // É inicializado sempre que a funcão function() é chamado!
    static int static_var = 5; // Só pode ser inicializado uma vez.

    printf("\t[in function] var = %d\n", var);
    printf("\t[in function] static_var = %d\n", static_var);
    
    var++;
    static_var++;
}

int main() {
    int i;
    static int static_var = 1337;

    for(i=0; i<5 ;i++) {
        printf("[in main] static_var = %d\n", static_var);
        function();
    }
}