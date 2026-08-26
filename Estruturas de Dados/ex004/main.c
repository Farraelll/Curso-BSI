// Une colecoes de "quadrinhos"

#include <stdio.h>
#include <stdlib.h>

int contem(const int* vetor, int tamanho, int id) {
	for (int i = 0; i < tamanho; i++) { if (vetor[i] == id) { return 1; } }
	return 0;
}

int* unir_colecoes(const int* colecao_herois_hq, const int* colecao_acao_comics,
				   int tamanho_herois_hq, int tamanho_acao_comics,
				   int* tamanho_final) {
	int capacidade = tamanho_herois_hq + tamanho_acao_comics;
	int* colecao_unificada = (int*)malloc(capacidade * sizeof(int));

	int n = 0;

	for (int i = 0; i < tamanho_herois_hq; i++) {
		if (!contem(colecao_unificada, n, colecao_herois_hq[i])) {
			colecao_unificada[n] = colecao_herois_hq[i];
			n++;
		}
	}

	for (int i = 0; i < tamanho_acao_comics; i++) {
		if (!contem(colecao_unificada, n, colecao_acao_comics[i])) {
			colecao_unificada[n] = colecao_acao_comics[i];
			n++;
		}
	}

	*tamanho_final = n;
	return colecao_unificada;
}

int main() {
	int colecao_herois_hq[] = {101, 102, 103, 104};
	int colecao_acao_comics[] = {201, 202, 203};
	int tamanho_herois_hq = 4;
	int tamanho_acao_comics = 3;
	int tamanho_final;

	int* colecao_unificada = unir_colecoes(colecao_herois_hq, colecao_acao_comics, tamanho_herois_hq,
										   tamanho_acao_comics, &tamanho_final);

	printf("Colecao unificada:");
	for (int i = 0; i < tamanho_final; i++) { printf(" %d", colecao_unificada[i]); }
	printf("\n");
	printf("Tamanho da colecao unificada: %d\n", tamanho_final);

	free(colecao_unificada);

	return 0;
}
