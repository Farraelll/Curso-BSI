#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dividirTexto(char *texto, char *parte1, char *parte2) {
    char *posicaoEspaco = strchr(texto, ' ');

    if (posicaoEspaco == NULL) {
        return 0;
    }

    int tamanhoParte1 = posicaoEspaco - texto;

    strncpy(parte1, texto, tamanhoParte1);
    parte1[tamanhoParte1] = '\0';

    strcpy(parte2, posicaoEspaco + 1);

    return 1;
}

int main() {
    char texto[] = "Bom dia";
    char parte1[20];
    char parte2[20];

    if (dividirTexto(texto, parte1, parte2)) {
        printf("Mensagem original: %s\n", texto);
        printf("Parte 1: %s\n", parte1);
        printf("Parte 2: %s\n", parte2);
    } else {
        printf("A string não contém espaço para divisão.\n");
    }

    return 0;
}