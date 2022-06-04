#ifndef LISTA2_H 
#define LISTA2_H

#include "lista.h"

typedef struct Item2 Item2;
typedef struct Block2 Block2;
typedef struct Lista2 Lista2;

struct Item2 {
	Item pos[2];
};

struct Block2{
	Item2 data;
	Block2 *prox;
};

struct Lista2{
	Block2 *first;
	Block2 *last;
};

void FL2Vazia(Lista2 *l);
void L2Insert(Lista2 *l, Item2 d);
void L2Imprime(Lista2 *l);

Lista2 Concatenate(Lista *l1, Lista *l2);

#endif