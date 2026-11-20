#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void list_print(struct list *l)
{
	struct element *aux;
	aux = l->first;

	printf("L = {");
	while(aux != NULL)
	{
		printf("%d", aux->value);
		if(aux->next != NULL)
			printf(" ");
		aux = aux->next;

	}
	printf("}\n");
}

struct element *new_element(int value)
{
	struct element *e = malloc(sizeof(struct element));

	e->value = value;
	e->next = NULL;

	return e;
}

void insert_first(struct list *l, struct element *new_element)
{
	new_element->next = l->first;
	l->first = new_element;
	l->n++;

	return;
}

void insert_last(struct list *l, struct element *new_element)
{
	struct element *aux = l->first;
	if(aux == NULL)
	{
		l->first = new_element;
		l->n++;
		return;
	}
	while(aux->next != NULL)
		aux = aux->next;
	aux->next = new_element;
	new_element->next = NULL;
	l->n++;
	return;
}

void remove_first(struct list *l)
{
	struct element *removido = l->first;
	if(removido == NULL)
		return;
	l->first = removido->next;
	l->n--;
	printf("o elemento de valor '%d' foi removido com sucesso!\n", removido->value);
	free(removido);
	return;	
}

void remove_last(struct list *l)
{
	struct element *removido = l->first;
	struct element *anterior = NULL;

	if(removido->next == NULL)
	{
		removido = NULL;
		l->n--;
	}
	while(removido->next != NULL)
	{
		anterior = removido;
		removido = removido->next;
	}
	anterior->next = NULL;
	printf("o elemento de valor '%d' foi removido com sucesso!\n", removido->value);
	l->n--;
	free(removido);
}

void remove_by_value(struct list *l, int value)
{
	struct element *anterior = NULL;
	struct element *removido = l->first;
	struct element *temp = NULL;

	if(removido == NULL)
		return;
	if(removido->value == value)
	{
		removido = NULL;
		l->n--;
	}
	while(removido != NULL)
	{
		if (removido->value == value)
		{
			anterior->next = removido->next;
			temp = removido;
			l->n--;
			printf("elemento de valor '%d' removido com sucesso!\n", removido->value);
			free(temp);
			return;

		}
		anterior = removido;
		removido = removido->next;
	}

}

void remove_by_index(struct list *l, int index)
{
	if(index > l->n)
	{
		return;
	}

	int i = 0;
	struct element *removido = l->first;
	struct element *anterior = NULL;
	struct element *temp = NULL;

	if(i == index)
	{
		l->first = removido->next;
		temp = removido;
		l->n--;
		printf("elemento de posição '%d' com valor '%d'foi removido com sucesso!\n", i, removido->value);
		free(temp);
		return;

	}
	while(i < index)
	{
		anterior = removido;
		removido = removido->next;
		i++;
	}
	anterior->next = removido->next;
	temp = removido;
	printf("elemento de posição '%d' com valor '%d'foi removido com sucesso!\n", i, removido->value);
	free(temp);	
	l->n--;
	return;
}

void free_list(struct list *l)
{
	struct element *atual = l->first;
	struct element *temp = NULL;

	if(l == NULL)
		return;

	while(atual != NULL)
	{
		temp = atual->next;
		free(atual);
		atual = temp;
		l->n--;
	}
	l->first = NULL;
	return;
}


