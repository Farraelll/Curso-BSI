#include "linkedlist.h"
#include <stdio.h>

int main(void) {
	printf("--- Teste ll_concatenated ---\n");

	LinkedList* lista1 = ll_create();
	ll_insert(lista1, 20);
	ll_insert(lista1, 10);

	LinkedList* lista2 = ll_create();
	ll_insert(lista2, 40);
	ll_insert(lista2, 30);

	printf("Original l1: ");
	ll_print(lista1);
	printf("Original l2: ");
	ll_print(lista2);

	LinkedList* listaConcatenada = ll_concatenated(lista1, lista2);

	printf("Concatenada (l1 + l2): ");
	ll_print(listaConcatenada);

	printf("\nLiberando memoria...\n");
	ll_free(lista1);
	ll_free(lista2);
	ll_free(listaConcatenada);

	printf("Testes concluidos.\n");
	return 0;
}
