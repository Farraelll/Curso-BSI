#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int is_matching_pair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    
    if (file == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'input.txt'.\n");
        return 1;
    }

    Stack *s = s_create();
    int c;
    int balanced = 1;

    while ((c = fgetc(file)) != EOF) 
    {
        if (c == '(' || c == '[' || c == '{') {
            s_push(s, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            
            if (s_is_empty(s)) {
                balanced = 0;
                break;
            }

            char top = s_pop(s);

            if (!is_matching_pair(top, c)) {
                balanced = 0;
                break;
            }
        }
    }

    if (balanced && !s_is_empty(s)) {
        balanced = 0;
    }

    if (balanced) {
        printf("sucess\n");
    } else {
        printf("fail\n");
    }

    s_free(s);
    fclose(file);

    return 0;
}