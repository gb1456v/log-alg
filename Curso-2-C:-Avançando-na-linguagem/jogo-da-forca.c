#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
//variáveis globais
char palavraSecreta[TAM_PALAVRA];
char chutes[26];//letras do alfabeto
int chutesDados = 0;
/*as variáveis globais devem ser utilizadas somente quando há certeza absoluta que 
todas as funções precisam das variáveis que estão sendo declaradas como globais*/
void adicionaPalavra() {
    char quer;
    printf("Você deseja adicionar uma nova palavra no jogo?(S/s/N/n)");
    scanf(" %c", &quer);
    if((quer == 'S') || (quer == 's')) {
        char novapalavra[TAM_PALAVRA];
        printf("Digite a nova palavra, em letras maiúsculas");
        scanf("%s", &novapalavra);
        FILE* f;
        f = fopen("palavras.txt", "r+");
        //r+ == leitura e escrita
        if(f == 0) {
            printf("Arquivo não disponível! Saindo...");
            exit(1);
        }

        int qtdPalavras;
        fscanf(f, "%d", &qtdPalavras);
        qtdPalavras++;
        //lê do arquivo a qtd de palavras e adicionei mais um à variável
        fseek(f, 0 ,SEEK_SET);
        // vai pro começo do arquivo
        fprintf(f, "%d", qtdPalavras);
        //escreve no arquivo o valor de qtdPalavras(anterior + 1)
        fseek(f, 0, SEEK_END);
        // vai pro final do arquivo
        fprintf(f, "\n%s", novapalavra);
        //escreve a nova palavra no arquivo
        fclose(f);
    }
}
void escolhe_palavra() {
    FILE* f;//declaração da variável usada no pra armazenar o arquivo aberto
    f = fopen("palavras.txt", "r"); // r de read e fopen pra abrir o arquivo
    int qtdDePalavras;
    fscanf(f,"%d",&qtdDePalavras); // lê o total de palavras do arquivo
    if(f == 0) {
        printf("Desculpe, banco de dados não disponível!");
        exit(1);
    }// tratamento de erros do arquivo
    srand(time(0));
    int linhaAleatoria = rand() % qtdDePalavras; // linha gerada até, no máximo, o total de linhas do arquivo

    for(int i = 0; i<= linhaAleatoria; i++) {
        fscanf(f,"%s", palavraSecreta);
    } // varre o arquivo até achar a linha aleatória e guarda a palavra da linha aleatória na variável palavra_secreta

}
void boas_vindas() {
    printf("*******************************************\n");
    printf("* Seja bem-vindo(a) ao jogo da forca! *\n Boa sorte!\n");
    printf("*******************************************\n");
}
void chuta_logo() {
    char chute; 
    scanf(" %c", &chute);
    chutes[(chutesDados)] = chute;
    (chutesDados)++;
}
int jachutou(char letra) {
    int achou = 0;
    for(int j = 0;j < chutesDados; j++) {
        if(chutes[j] == letra) {
            //verifica se a letra digitada está na palavra secreta
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenha_forca() {
    int erros = chuteserrados();
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
        (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
        (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), 
        (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
    for(int i = 0; i < strlen(palavraSecreta); i++) {
        //vai percorrer o a palavra e pedir os chuites
        int achou = jachutou(palavraSecreta[i]);
        if(achou) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int enforcou() {
    return chutesErrados() >= 5;
}
int chutesErrados() {
        int erros = 0;
    for(int i=0; i< chutesDados; i++) {
        //varre os chutes
        int existe = 0;
        for(int j= 0; j < strlen(palavraSecreta); j++) {
            //varre a palavra secreta
            if(chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}
int acertou() {
    for(int i=0; i < strlen(palavraSecreta);i++) {
        //varre a palavra secreta
        if(!jachutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char chute;
    int achou;
    boas_vindas();
    escolhe_palavra(palavraSecreta[TAM_PALAVRA]);
    do //executa primeiro
    {
        desenha_forca();
        chuta_logo();
    } while(!ganhou() && !enforcou());
    if(!ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n"); 
    }
    // verica se precisa executar o código depois de executar ele uma vez
}