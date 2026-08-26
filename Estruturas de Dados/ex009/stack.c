#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct stack {
	StackNode* top;
};

struct stacknode {
	char info;
	StackNode* next;
};

Stack* s_create() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = nullptr;
	return s;
}

int s_is_empty(const Stack* s) { return s->top == NULL; }

void s_push(Stack* s, char v) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->info = v;
	node->next = s->top;
	s->top = node;
}

char s_top(const Stack* s) {
	assert(!s_is_empty(s));
	return s->top->info;
}

char s_pop(Stack* s) {
	assert(!s_is_empty(s));

	char v = s->top->info;
	StackNode* p = s->top;
	s->top = s->top->next;
	free(p);
	return v;
}

void s_free(Stack* s) {
	StackNode* p = s->top;
	while (p != NULL) {
		StackNode* t = p->next;
		free(p);
		p = t;
	}
	free(s);
}

void s_print(const Stack* s) {
	for (StackNode* p = s->top; p != NULL; p = p->next)
		printf("%c ", p->info);

	printf("\n");
}
