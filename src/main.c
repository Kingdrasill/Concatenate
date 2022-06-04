#include "lista2.h"

int main()
{
	srand(42);
	Lista l1, l2;
    Lista2 l3;
    int size=0;

	FLVazia(&l1);
	FLVazia(&l2);
    FL2Vazia(&l3);

    printf("\nTamanho das listas: ");
    scanf("%d", &size);

    Initialize(&l1, size);
    Initialize(&l2, size);
    
    printf("\nLista x: ");
    LImprime(&l1);
    printf("\nLista y: ");
    LImprime(&l2);

    l3 = Concatenate(&l1, &l2);
    printf("\nListas Concatenadas: ");
    L2Imprime(&l3);
    
    printf("\nLista x: ");
    LImprime(&l1);
    printf("\nLista y: ");
    LImprime(&l2);

	return 0;
}