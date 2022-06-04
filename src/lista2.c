#include "lista2.h"

void FL2Vazia(Lista2 *l){
	l->first = (Block2*) malloc (sizeof(Block2));
	l->last  = l->first;
	l->first->prox = NULL;
}

void L2Insert(Lista2 *l, Item2 d){
	l->last->prox = (Block2*) malloc (sizeof(Block2));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void L2Imprime(Lista2 *l){
	Block2 *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("(%d , %d) ", aux->data.pos[0].val, aux->data.pos[1].val);
		aux = aux->prox;
	}
	printf("\n");
}

Lista2 Concatenate(Lista *l1, Lista *l2) {
    Item2 aux;
    Item x, y;
    Lista2 l3;
    FL2Vazia(&l3);

    while (l1->first != l1->last && l2->first != l2->last)
    {
        x = RemoveFirst(l1);
        y = RemoveLast(l2);
        aux.pos[0] = x;
        aux.pos[1] = y;

        L2Insert(&l3, aux);
    }

    return l3; 
}