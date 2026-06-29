#include "dynvec.h"
#include <stdio.h>
#include <stdlib.h>

struct dynvec {
	int* dados;
	int tamanho;
	int capacidade;
};

DynVec* dv_create() {
	DynVec* dv = malloc(sizeof(DynVec));

	if (dv == NULL) { return nullptr; }

	dv->capacidade = 4;
	dv->tamanho = 0;
	dv->dados = malloc(dv->capacidade * sizeof(int));

	if (dv->dados == NULL) {
		free(dv);
		return nullptr;
	}

	return dv;
}

int dv_size(const DynVec* dv) {
	if (dv == NULL) { return 0; }

	return dv->tamanho;
}

int dv_get(const DynVec* dv, int indice) {
	if (dv == NULL || indice < 0 || indice >= dv->tamanho) { return 0; }

	return dv->dados[indice];
}

void dv_append(DynVec* dv, int valor) {
	if (dv == NULL) { return; }

	if (dv->tamanho == dv->capacidade) {
		int novaCapacidade = dv->capacidade * 2;
		int* novosDados = realloc(dv->dados, novaCapacidade * sizeof(int));

		if (novosDados == NULL) { return; }

		dv->dados = novosDados;
		dv->capacidade = novaCapacidade;
	}

	dv->dados[dv->tamanho] = valor;
	dv->tamanho++;
}

int dv_is_in(const DynVec* dv, int valor) {
	if (dv == NULL) { return 0; }

	for (int i = 0; i < dv->tamanho; i++) { if (dv->dados[i] == valor) { return 1; } }

	return 0;
}

DynVec* dv_concatenate(const DynVec* dv1, const DynVec* dv2) {
	DynVec* resultado = dv_create();

	if (resultado == NULL) { return nullptr; }

	for (int i = 0; i < dv_size(dv1); i++) { dv_append(resultado, dv_get(dv1, i)); }

	for (int i = 0; i < dv_size(dv2); i++) { dv_append(resultado, dv_get(dv2, i)); }

	return resultado;
}

DynVec* dv_union(const DynVec* dv1, const DynVec* dv2) {
	DynVec* resultado = dv_create();

	if (resultado == NULL) { return nullptr; }

	for (int i = 0; i < dv_size(dv1); i++) {
		int valor = dv_get(dv1, i);

		if (!dv_is_in(resultado, valor)) { dv_append(resultado, valor); }
	}

	for (int i = 0; i < dv_size(dv2); i++) {
		int valor = dv_get(dv2, i);

		if (!dv_is_in(resultado, valor)) { dv_append(resultado, valor); }
	}

	return resultado;
}

DynVec* dv_intersection(const DynVec* dv1, const DynVec* dv2) {
	DynVec* resultado = dv_create();

	if (resultado == NULL) { return nullptr; }

	for (int i = 0; i < dv_size(dv1); i++) {
		int valor = dv_get(dv1, i);

		if (dv_is_in(dv2, valor) && !dv_is_in(resultado, valor)) { dv_append(resultado, valor); }
	}

	return resultado;
}

void dv_free(DynVec* dv) {
	if (dv == NULL) { return; }

	free(dv->dados);
	free(dv);
}

void dv_print(const DynVec* dv) {
	if (dv == NULL) {
		printf("[]\n");
		return;
	}

	printf("[");

	for (int i = 0; i < dv->tamanho; i++) {
		printf("%d", dv->dados[i]);

		if (i < dv->tamanho - 1) { printf(", "); }
	}

	printf("]\n");
}
