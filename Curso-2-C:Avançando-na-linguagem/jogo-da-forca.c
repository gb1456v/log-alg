#include <stdio.h>
#include <string.h>
void boas_vindas() {
    printf("*******************************************\n");
    printf("* Seja bem-vindo(a) ao jogo da forca! *\n Boa sorte!\n");
    printf("*******************************************\n");
}
void chuta_logo(char chutes[26], char chute, int tentativas) {
    scanf(" %c", &chute);
    chutes[tentativas] = chute;
    tentativas++;
}
int main() {
    char palavra_secreta[10];
    int acertou = 0;
    int enforcou = 0;
    char chute;
    char chutes[26];//letras do alfabeto
    int tentativas = 0;
    sprintf(palavra_secreta, "MELANCIA");
    boas_vindas();
    do {
        for(int i = 0; strlen(palavra_secreta); i++) {
            int achou = 0;
            for(int j = 0;j < tentativas; j++) {
                if(chutes[j] == palavra_secreta[i]) {
                    achou = 1;
                    break;
                }
            }
            if(achou == 1) {
                printf("%c ", palavra_secreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
        chuta_logo(chutes, chute, tentativas);
    } while(!acertou && !enforcou);
}