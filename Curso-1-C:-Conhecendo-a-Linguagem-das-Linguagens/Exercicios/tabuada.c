#include <stdio.h>

int main() {
    int numero_escolhido, res;
    printf("Você quer tabuada de qual número?\n");
    scanf("%d",&numero_escolhido);
    for(int i=1;i<=10;i++) {
        res = numero_escolhido * i;
        printf("%d x %d = %d \n", numero_escolhido,i, res);
    }
}