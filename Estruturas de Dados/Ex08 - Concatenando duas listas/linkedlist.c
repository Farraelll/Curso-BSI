#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    ListNode *primeiro;
};

struct list_node
{
    int info;
    ListNode *proximo;
};

LinkedList *ll_create()
{
    LinkedList *lista = (LinkedList *)malloc(sizeof(LinkedList));
    lista->primeiro = NULL;
    return lista;
}

int ll_is_empty(LinkedList *lista)
{
    return lista->primeiro == NULL;
}

void ll_insert(LinkedList *lista, int valor)
{
    ListNode *no = (ListNode *)malloc(sizeof(ListNode));
    no->info = valor;
    no->proximo = lista->primeiro;
    lista->primeiro = no;
}

int ll_size(LinkedList *lista)
{
    int contador = 0;
    for (ListNode *noAtual = lista->primeiro; noAtual != NULL; noAtual = noAtual->proximo)
    {
        contador++;
    }
    return contador;
}

int ll_is_in(LinkedList *lista, int valor)
{
    ListNode *noAtual = lista->primeiro;
    while (noAtual != NULL)
    {
        if (noAtual->info == valor)
            return 1;
        noAtual = noAtual->proximo;
    }
    return 0;
}

int ll_remove(LinkedList *lista, int valor)
{
    ListNode *noAtual = lista->primeiro;
    ListNode *noAnterior = NULL;

    while (noAtual != NULL)
    {
        if (noAtual->info == valor)
        {
            if (noAnterior == NULL)
                lista->primeiro = noAtual->proximo;
            else
                noAnterior->proximo = noAtual->proximo;

            free(noAtual);
            return 1;
        }
        else
        {
            noAnterior = noAtual;
            noAtual = noAtual->proximo;
        }
    }

    return 0;
}

void ll_remove_all(LinkedList *lista, int valor)
{
    while (ll_remove(lista, valor))
        ;
}

void ll_free(LinkedList *lista)
{
    ListNode *noAtual = lista->primeiro;
    while (noAtual != NULL)
    {
        ListNode *temp = noAtual->proximo;
        free(noAtual);
        noAtual = temp;
    }
    free(lista);
}

void ll_print(LinkedList *lista)
{
    for (ListNode *noAtual = lista->primeiro; noAtual != NULL; noAtual = noAtual->proximo)
    {
        printf("%d ", noAtual->info);
    }
    printf("\n");
}

LinkedList *ll_concatenated(LinkedList *lista1, LinkedList *lista2)
{
    LinkedList *novaLista = ll_create();
    ListNode *ultimoNo = NULL;
    ListNode *noAtual;

    noAtual = lista1->primeiro;
    while (noAtual != NULL)
    {
        ListNode *novoNo = (ListNode *)malloc(sizeof(ListNode));
        novoNo->info = noAtual->info;
        novoNo->proximo = NULL;

        if (novaLista->primeiro == NULL)
        {
            novaLista->primeiro = novoNo;
            ultimoNo = novoNo;
        }
        else
        {
            ultimoNo->proximo = novoNo;
            ultimoNo = novoNo;
        }
        noAtual = noAtual->proximo;
    }

    noAtual = lista2->primeiro;
    while (noAtual != NULL)
    {
        ListNode *novoNo = (ListNode *)malloc(sizeof(ListNode));
        novoNo->info = noAtual->info;
        novoNo->proximo = NULL;

        if (novaLista->primeiro == NULL)
        {
            novaLista->primeiro = novoNo;
            ultimoNo = novoNo;
        }
        else
        {
            ultimoNo->proximo = novoNo;
            ultimoNo = novoNo;
        }
        noAtual = noAtual->proximo;
    }

    return novaLista;
}