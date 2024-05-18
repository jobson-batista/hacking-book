#include <stdio.h>
#include <stdlib.h>

/* Estrutura da memória
    0 - Segmento de texto/código        Endereços baixos
    1 - Segmento de dados
    2 - Segmento bss
    3 - Segmento heap
    4 - Segmento da pilha               Endereços altos

    Segmento de dados -> Variáveis static e globais inicializadas.
    Segmentos bss -> Variáveis static e globais não inicializadas.

*/

int global_var;
int global_initialized_var = 5;

void function() {
    int stack_var; // Essa variavel possui o mesmo nome que a variavel em main()

    printf("[function] O endereço da variável stack_var é: %p\n", &stack_var);
}

int main() {
    int stack_var; // Mesmo nome que a variacel em function()
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *) malloc(4);

    // Essas variáveis estão no segmento de dados.
    printf("global_initialized_var está no endereço %p\n", &global_initialized_var);
    printf("static_initialized_var está no endereço %p\n\n", &static_initialized_var);

    // Essas variáveis estão no segmento bss.
    printf("static_var está no endereço %p\n", &static_var);
    printf("global_var está no endereço %p\n\n", &global_var);

    // Essa variáveis estão no segmento do heap.
    printf("heap_var está no endereço %p\n\n", &heap_var_ptr);

    // Essa variável está no segmento de pilha.
    printf("stack_var está no endereço %p\n\n", & stack_var);
    
    function();
}