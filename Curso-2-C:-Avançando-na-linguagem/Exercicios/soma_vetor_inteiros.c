#include <stdio.h>

int soma_inteiros(int* numeros, int tamanho) {
    int soma = 0;
    for(int i= 0; i < tamanho;i++) {
        soma = soma + numeros[i];
    }
    return soma;
}
int main() {
    int numeros[3],resultado;
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    resultado = soma_inteiros(numeros,3);
    printf("Resultado da soma: %d", resultado);
    return 0;
}