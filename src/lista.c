#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last) {
				l->last = tmp;
            }
			free(aux);
		}
		else
			aux = aux->prox;
	}
}

void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d ", aux->data.val);
		aux = aux->prox;
	}
	printf("\n");

}

void Initialize(Lista *l, int size) {
    Item aux;

    for(int i=0; i<size; i++) {
        aux.val = rand()%100;
        LInsert(l, aux);
    }
}

Item RemoveFirst(Lista *l) {
	Block *aux, *tmp;
	Item first;

	tmp = l->first;
	aux = tmp->prox;
	first = aux->data;
	tmp->prox = aux->prox;
	free(aux);

	return first;
}

Item RemoveLast(Lista *l) {
	Block *aux, *tmp;
	Item last;

	aux = l->last;
	last = aux->data;
	tmp = l->first;

	while(tmp->prox != aux) {
		tmp = tmp->prox;
	}
	tmp->prox = aux->prox;
	l->last = tmp;
	free(aux);

	return last;
}