#include <stdio.h>

int main() {
    
    int idade = 24;
    int* pIdade = &idade;

    // imprime o valor de idade atraves de acesso direto
    printf("%d \n", idade);

    // imprime o valor de idade atraves do desreferenciamento pelo ponteiro
    printf("%d \n", *pIdade);

    // altera o valor de idade atraves de acesso direto
    idade = 25;
    printf("%d \n", idade);

    // altera o valor de idade atraves do ponteiro
    *pIdade = 26;
    printf("%d \n", idade);

    return 0;
}