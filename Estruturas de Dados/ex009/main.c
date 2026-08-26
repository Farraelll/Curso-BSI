// Analise sintatica

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int is_matching_pair(char open, char close) {
	if (open == '(' && close == ')') return 1;
	if (open == '[' && close == ']') return 1;
	if (open == '{' && close == '}') return 1;

	return 0;
}

int main(int argc, char* argv[]) {
	const char* file_path = "input.txt";

	if (argc > 1) { file_path = argv[1]; }

	FILE* file = fopen(file_path, "r");

	if (file == NULL) {
		printf("Erro: Nao foi possivel abrir o arquivo '%s'.\n", file_path);
		return 1;
	}

	Stack* s = s_create();

	if (s == NULL) {
		printf("Erro: nao foi possivel criar a pilha.\n");
		fclose(file);
		return 1;
	}

	int c;
	int balanced = 1;

	while ((c = fgetc(file)) != EOF) {
		if (c == '(' || c == '[' || c == '{') {
			if (!s_push(s, (char)c)) {
				printf("Erro: falha ao empilhar caractere.\n");
				s_free(s);
				fclose(file);
				return 1;
			}
		}
		else if (c == ')' || c == ']' || c == '}') {
			char top;

			if (!s_pop(s, &top)) {
				balanced = 0;
				break;
			}

			if (!is_matching_pair(top, (char)c)) {
				balanced = 0;
				break;
			}
		}
	}

	if (balanced && !s_is_empty(s)) { balanced = 0; }

	if (balanced) { printf("success\n"); }
	else { printf("fail\n"); }

	s_free(s);
	fclose(file);

	return 0;
}
