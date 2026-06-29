#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rodadas 3

char escolheJogada() {
    int escolha = 1 + rand() % 3;
    if (escolha < 2) {
        return 'r';
    }
    else if (escolha == 2) {
        return 'p';
    }
    else {
        return 't';
    }
}

int main() {
    char humano, maquina;
    int vitorias = 0, empates = 0;
    srand(time(NULL));

    for (int c = 0; c < rodadas; c++) {

        printf("\nHumano, escolha pedra(r), papel(p) ou tesoura(t): \n");
        scanf(" %c", &humano);
        system("clear");
        maquina = escolheJogada();

        if (humano == maquina) {
            printf("Empate");
            empates++;
        }
        else if (humano == 'r' &&  maquina == 'p') {
            printf("Derrota");
        }
        else if (humano == 'p' &&  maquina == 't') {
            printf("Derrota");
        }
        else if (humano == 't' &&  maquina == 'r') {
            printf("Derrota");
        }
        else {
            printf("Vitória");
            vitorias++;
        };
    };
    printf("\nRodadas: %i\n", rodadas);
    system("clear");
    printf("\nHumano: %d\n", vitorias);
    printf("Maquina: %d\n", (rodadas - vitorias) - empates);
    printf("Empates: %d\n", empates);
    return 0;
}