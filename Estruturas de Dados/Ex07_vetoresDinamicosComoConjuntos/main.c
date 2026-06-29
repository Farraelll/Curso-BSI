#include "dynvec.h"
#include <stdio.h>

int main(void) {
	DynVec* dv1 = dv_create();
	dv_append(dv1, 1);
	dv_append(dv1, 2);
	dv_append(dv1, 3);
	dv_append(dv1, 4);

	DynVec* dv2 = dv_create();
	dv_append(dv2, 3);
	dv_append(dv2, 4);
	dv_append(dv2, 5);
	dv_append(dv2, 6);

	printf("dv1: ");
	dv_print(dv1);
	printf("dv2: ");
	dv_print(dv2);

	printf("\n--- Concatenacao (dv1 + dv2) ---\n");
	DynVec* concatenado = dv_concatenate(dv1, dv2);
	dv_print(concatenado);

	printf("\n--- Uniao (dv1 U dv2) ---\n");
	DynVec* uniao = dv_union(dv1, dv2);
	dv_print(uniao);

	printf("\n--- Intersecao (dv1 ^ dv2) ---\n");
	DynVec* intersecao = dv_intersection(dv1, dv2);
	dv_print(intersecao);

	printf("\nLiberando memoria...\n");
	dv_free(dv1);
	dv_free(dv2);
	dv_free(concatenado);
	dv_free(uniao);
	dv_free(intersecao);

	printf("Testes concluidos.\n");
	return 0;
}
