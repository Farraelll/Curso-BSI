#include <stdio.h>

int jogada_valida(char jogada)
{
    return jogada == 'r' || jogada == 'p' || jogada == 't';
}

int main()
{
    char primeiro;
    char segundo;

    printf("Primeiro jogador, escolha pedra(r), papel(p) ou tesoura(t):\n");
    if (scanf(" %c", &primeiro) != 1) {
        printf("Entrada inválida.\n");
        return 1;
    }

    printf("\nSegundo jogador, escolha pedra(r), papel(p) ou tesoura(t):\n");
    if (scanf(" %c", &segundo) != 1) {
        printf("Entrada inválida.\n");
        return 1;
    }

    if (!jogada_valida(primeiro) || !jogada_valida(segundo)) {
        printf("Jogada inválida. Use apenas r, p ou t.\n");
        return 1;
    }

    if (primeiro == segundo) {
        printf("Empate");
    }
    else if ((primeiro == 'r' && segundo == 'p') ||
             (primeiro == 'p' && segundo == 't') ||
             (primeiro == 't' && segundo == 'r'))
    {
        printf("Segundo jogador ganhou.");
    }
    else {
        printf("Primeiro jogador ganhou.");
    }

    printf("\nJogador 1: %c\nJogador 2: %c\n", primeiro, segundo);

    return 0;
}