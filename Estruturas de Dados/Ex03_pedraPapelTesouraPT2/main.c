#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RODADAS 3

int jogada_valida(char jogada) { return jogada == 'r' || jogada == 'p' || jogada == 't'; }

char escolheJogada() {
	int escolha = 1 + rand() % 3;

	if (escolha == 1) { return 'r'; }
	else if (escolha == 2) { return 'p'; }
	else { return 't'; }
}

int main() {
	char humano;
	int vitorias = 0;
	int empates = 0;
	int derrotas = 0;

	srand((unsigned int)time(nullptr));

	for (int c = 0; c < RODADAS; c++) {
		printf("\nRodada %d de %d\n", c + 1, RODADAS);
		printf("Humano, escolha pedra(r), papel(p) ou tesoura(t):\n");

		if (scanf(" %c", &humano) != 1) {
			printf("Entrada inválida.\n");
			return 1;
		}

		if (!jogada_valida(humano)) {
			printf("Jogada inválida. Use apenas r, p ou t.\n");
			c--;
			continue;
		}

		char maquina = escolheJogada();

		printf("Humano: %c\n", humano);
		printf("Máquina: %c\n", maquina);

		if (humano == maquina) {
			printf("Empate\n");
			empates++;
		}
		else if ((humano == 'r' && maquina == 'p') ||
			(humano == 'p' && maquina == 't') ||
			(humano == 't' && maquina == 'r')) {
			printf("Derrota\n");
			derrotas++;
		}
		else {
			printf("Vitória\n");
			vitorias++;
		}
	}

	printf("\nRodadas: %d\n", RODADAS);
	printf("Humano: %d\n", vitorias);
	printf("Máquina: %d\n", derrotas);
	printf("Empates: %d\n", empates);

	return 0;
}
