#ifndef LISTA_H
#define LISTA_H


// estrutura de nó para a lista encadeada

struct element 
{
	int value;
	struct element *next;
};



struct list
{
	struct element *first;
	int n;
};

// printar a lista na tela 
void list_print(struct list *l);

// criação e  inserção de elementos
struct element *new_element(int value);
void insert_first(struct list *l, struct element *new_element);
void insert_last(struct list *l, struct element *new_element);

// remoção de elementos e liberação da lista
void remove_first(struct list *l);
void remove_last(struct list *l);
void remove_by_value(struct list *l, int value);
void remove_by_index(struct list *l, int index);
void free_list(struct list *l);

#endif
