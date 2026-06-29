#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list {
	ListNode* primeiro;
};

struct list_node {
	int info;
	ListNode* proximo;
};

LinkedList* ll_create() {
	LinkedList* lista = malloc(sizeof(LinkedList));

	if (lista == NULL) { return nullptr; }

	lista->primeiro = nullptr;
	return lista;
}

int ll_is_empty(const LinkedList* lista) { return lista == NULL || lista->primeiro == NULL; }

void ll_insert(LinkedList* lista, int valor) {
	if (lista == NULL) { return; }

	ListNode* no = malloc(sizeof(ListNode));

	if (no == NULL) { return; }

	no->info = valor;
	no->proximo = lista->primeiro;
	lista->primeiro = no;
}

int ll_size(const LinkedList* lista) {
	if (lista == NULL) { return 0; }

	int contador = 0;

	for (ListNode* noAtual = lista->primeiro; noAtual != NULL; noAtual = noAtual->proximo) { contador++; }

	return contador;
}

int ll_is_in(const LinkedList* lista, int valor) {
	if (lista == NULL) { return 0; }

	ListNode* noAtual = lista->primeiro;

	while (noAtual != NULL) {
		if (noAtual->info == valor) { return 1; }

		noAtual = noAtual->proximo;
	}

	return 0;
}

int ll_remove(LinkedList* lista, int valor) {
	if (lista == NULL) { return 0; }

	ListNode* noAtual = lista->primeiro;
	ListNode* noAnterior = nullptr;

	while (noAtual != NULL) {
		if (noAtual->info == valor) {
			if (noAnterior == NULL) { lista->primeiro = noAtual->proximo; }
			else { noAnterior->proximo = noAtual->proximo; }

			free(noAtual);
			return 1;
		}

		noAnterior = noAtual;
		noAtual = noAtual->proximo;
	}

	return 0;
}

void ll_remove_all(LinkedList* lista, int valor) {
	if (lista == NULL) { return; }

	while (ll_remove(lista, valor)) {}
}

void ll_free(LinkedList* lista) {
	if (lista == NULL) { return; }

	ListNode* noAtual = lista->primeiro;

	while (noAtual != NULL) {
		ListNode* temp = noAtual->proximo;
		free(noAtual);
		noAtual = temp;
	}

	free(lista);
}

void ll_print(const LinkedList* lista) {
	if (lista == NULL) {
		printf("\n");
		return;
	}

	for (ListNode* noAtual = lista->primeiro; noAtual != NULL; noAtual = noAtual->proximo) {
		printf("%d ", noAtual->info);
	}

	printf("\n");
}

static int ll_append_node(LinkedList* lista, ListNode** ultimoNo, int valor) {
	if (lista == NULL || ultimoNo == NULL) { return 0; }

	ListNode* novoNo = malloc(sizeof(ListNode));

	if (novoNo == NULL) { return 0; }

	novoNo->info = valor;
	novoNo->proximo = nullptr;

	if (lista->primeiro == NULL) {
		lista->primeiro = novoNo;
		*ultimoNo = novoNo;
	}
	else {
		(*ultimoNo)->proximo = novoNo;
		*ultimoNo = novoNo;
	}

	return 1;
}

LinkedList* ll_concatenated(const LinkedList* lista1, const LinkedList* lista2) {
	LinkedList* novaLista = ll_create();

	if (novaLista == NULL) { return nullptr; }

	ListNode* ultimoNo = nullptr;

	if (lista1 != NULL) {
		for (ListNode* noAtual = lista1->primeiro; noAtual != NULL; noAtual = noAtual->proximo) {
			if (!ll_append_node(novaLista, &ultimoNo, noAtual->info)) {
				ll_free(novaLista);
				return nullptr;
			}
		}
	}

	if (lista2 != NULL) {
		for (ListNode* noAtual = lista2->primeiro; noAtual != NULL; noAtual = noAtual->proximo) {
			if (!ll_append_node(novaLista, &ultimoNo, noAtual->info)) {
				ll_free(novaLista);
				return nullptr;
			}
		}
	}

	return novaLista;
}
