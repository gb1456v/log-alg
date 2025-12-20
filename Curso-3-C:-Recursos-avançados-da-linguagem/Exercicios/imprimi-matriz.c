#include <stdio.h>
#define LINHA 3
#define COLUNA 2
int main() {
    int numeros[LINHA][COLUNA];
    for(int i=0;i< LINHA;i++) {
        for(int j = 0;j < COLUNA;j++) {
            printf("Digite um número:\n");
            scanf("%d", &numeros[i][j]);
        }
    }
    for(int i=0;i< LINHA;i++) {
        for(int j = 0;j < COLUNA;j++) {
            printf("%d\n", numeros[i][j]);
        }
    }
}