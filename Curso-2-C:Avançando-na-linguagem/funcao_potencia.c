#include <stdio.h>
int calcula_p(int a, int b) {
    int res = 1;
    for(int i = 0; i < b ; i++) {
        res = res * a;
    } 
}
int main() {
    int a,b;
    printf("Você quer calcular a potência de qual número?");
    scanf("%d", &a);//2
    printf("E você quer elevar este número em qual potência?");
    scanf("%d", &b);//3
    calcula_p(a,b);
}