#include <stdio.h>
int calcula_p(int* res, int a, int b) {
    for(int i = 0; i < b ; i++) {
        *res = *res * a;
    } 
    return *res;
}
int main() {
    int a,b,res, resultado;
    printf("Você quer calcular a potência de qual número?\n");
    scanf("%d", &a);//2
    printf("E você quer elevar este número em qual potência?\n");
    scanf("%d", &b);//3
    res = 1;
    resultado = calcula_p(&res, a, b);
    printf("O resultado do número %d elevado à potência %d é: %d \n", a,b,resultado);
}