#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f;
    f = fopen("teste.txt","r");
    //fopen("nomedoarquivo","r = leitura");
    if(f == 0) {
        printf("Arquivo não disponível!");
        exit(1);
    }
}