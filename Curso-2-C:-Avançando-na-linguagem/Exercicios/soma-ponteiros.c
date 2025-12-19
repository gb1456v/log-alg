#include <stdio.h>
int soma(int* num,int a, int b) {
    *num = a + b;
    return (*num);
}
int main() {
    int a, b, res, num;
    printf("Calculadora de soma de dois números\n");
    printf("Digite um número:\n");
    scanf("%d", &a);
    printf("Digite outro número:\n");
    scanf("%d", &b);
    res = soma(&num, a,b);
    printf("%d", num);
    return 0;

}