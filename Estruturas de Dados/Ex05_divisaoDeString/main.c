#include <stdio.h>
#include <string.h>

int dividirTexto(const char* texto, char* parte1, size_t tamanhoParte1Buffer, char* parte2,
				 size_t tamanhoParte2Buffer) {
	const char* posicaoEspaco = strchr(texto, ' ');

	if (posicaoEspaco == NULL) { return 0; }

	size_t tamanhoParte1 = (size_t)(posicaoEspaco - texto);
	size_t tamanhoParte2 = strlen(posicaoEspaco + 1);

	if (tamanhoParte1 >= tamanhoParte1Buffer || tamanhoParte2 >= tamanhoParte2Buffer) { return 0; }

	strncpy(parte1, texto, tamanhoParte1);
	parte1[tamanhoParte1] = '\0';

	strcpy(parte2, posicaoEspaco + 1);

	return 1;
}

int main() {
	char texto[] = "Bom dia";
	char parte1[20];
	char parte2[20];

	if (dividirTexto(texto, parte1, sizeof(parte1), parte2, sizeof(parte2))) {
		printf("Mensagem original: %s\n", texto);
		printf("Parte 1: %s\n", parte1);
		printf("Parte 2: %s\n", parte2);
	}
	else { printf("A string não pôde ser dividida com segurança.\n"); }

	return 0;
}
