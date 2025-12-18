#include <stdio.h>
#include <string.h>
#include "functions.h"
//variáveis globais
char palavra_secreta[20];
char chutes[26];//letras do alfabeto
int chutesdados = 0;
/*as variáveis globais devem ser utilizadas somente quando há certeza absoluta que 
todas as funções precisam das variáveis que estão sendo declaradas como globais*/
void escolhe_palavra() {
    sprintf(palavra_secreta,"MELANCIA");
}
void boas_vindas() {
    printf("*******************************************\n");
    printf("* Seja bem-vindo(a) ao jogo da forca! *\n Boa sorte!\n");
    printf("*******************************************\n");
}
void chuta_logo() {
    char chute; 
    scanf(" %c", &chute);
    chutes[(chutesdados)] = chute;
    (chutesdados)++;
}
int jachutou(char letra) {
    int achou = 0;
    for(int j = 0;j < chutesdados; j++) {
        if(chutes[j] == letra) {
            //verifica se a letra digitada está na palavra secreta
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenha_forca() {
    for(int i = 0; i < strlen(palavra_secreta); i++) {
        //vai percorrer o a palavra e pedir os chuites
        int achou = jachutou(palavra_secreta[i]);
        if(achou) {
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int enforcou() {
    int erros = 0;
    for(int i=0; i< chutesdados; i++) {
        //varre os chutes
        int existe = 0;
        for(int j= 0; j < strlen(palavra_secreta); j++) {
            //varre a palavra secreta
            if(chutes[i] == palavra_secreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
    //se a letra não existir na palavra e o usuário errar mais que 5 vezes, o jogo acaba.

}
int acertou() {
    for(int i=0; i < strlen(palavra_secreta);i++) {
        //varre a palavra secreta
        if(!jachutou(palavra_secreta[i])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char chute;
    int achou;
    boas_vindas();
    escolhe_palavra(palavra_secreta[20]);
    do //executa primeiro
    {
        desenha_forca(  );
        chuta_logo();
    } while(!acertou() && !enforcou());
    // verica se precisa executar o código depois de executar ele uma vez
}