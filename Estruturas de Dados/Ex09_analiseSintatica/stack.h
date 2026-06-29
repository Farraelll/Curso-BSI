#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;
typedef struct stacknode StackNode;

Stack *s_create();

int s_pop(Stack *s, char *valor);

int s_top(Stack *s, char *valor);

int s_push(Stack *s, char v);

int s_is_empty(Stack *s);

void s_free(Stack *s);

void s_print(Stack *s);

#endif