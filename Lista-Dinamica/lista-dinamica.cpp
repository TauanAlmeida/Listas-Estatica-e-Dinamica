#include <stdio.h>
#include <stdlib.h>
#include "lista-dinamica.h"

int main(){
	LISTA_ENC li;
	cria_lista(&li);
	eh_vazia (li);
	ins (&li, 1, 1);
	ins (&li, 2, 2);
	ins (&li, 3, 3);
	ins (&li, 4, 4);
//	gera_lista(&li, 5, 10);
//insere_ordenado(&li, 6);
//insere_ordenado(&li, 3);
//insere_ordenado(&li, 2);
//insere_ordenado(&li, 4);

	imprimi_lista(&li);
	remove_com_base_no_valor(&li, 2);
	imprimi_lista(&li);
//pertence(&li, 4);
//	eh_ordenada(&li);
}

void remove_com_base_no_valor(LISTA_ENC *pl, int valor){
	NODO *aux;
	NODO *ant;
	int cont=0;
	aux = (NODO *) malloc (sizeof(NODO));
//	for (aux=*pl;aux->inf!=valor;aux=aux->next)ant=aux->next;
	for (aux=*pl;aux->inf!=valor;aux=aux->next){
		cont++;
		ant=aux;
	}
	if (cont==0){
		free()
	}
	ant->next = aux->next;
//	return *pl;
}


LISTA_ENC insere_ordenado(LISTA_ENC *pl, int valor){
	NODO *novo;
	novo = (NODO *) malloc (sizeof(NODO));
	if (*pl == NULL){
		novo->next= NULL;
		novo->inf=valor;
		*pl=novo;
		return *pl;
	}else{
		int aux2;
		novo->inf=valor;
		novo->next=NULL;
		NODO *aux;
		for (aux=*pl;aux->next!=NULL;aux=aux->next);
		aux->next=novo;
		for(aux=*pl;aux->next!=NULL;aux=aux->next){
			if (novo->inf<aux->inf){
			aux2 = aux->inf;
			aux->inf = novo->inf;
			novo->inf = aux2;
			}
		}
		return *pl;
	}
}
void gera_lista(LISTA_ENC* pl, int m, int n){
NODO *novo;
int k=1;
	for (m;m<=n;m++){
		novo = (NODO *) malloc (sizeof(NODO));
	if (!novo) { printf ("\nERRO! Memoria insuficiente!\n");
		exit (2); 
	}
	novo->inf = m;
	if (k==1){
		novo->next = *pl;
		*pl = novo;
	}else{
		LISTA_ENC aux;
	for (aux=*pl; k>2; aux=aux->next, k--);
		novo->next = aux->next;
		aux->next = novo;
	}
k++;
	}
}

int eh_ordenada(LISTA_ENC *pl){
	NODO* aux;
	aux = (NODO *) malloc (sizeof(NODO));
	aux = *pl;
	while(aux->next){
		if (aux->inf < aux->next->inf){
		}else{
			printf ("n ordenada!\n");
		return 0;
		}
		aux = aux->next;
	}
	printf ("ordenada!\n");
	return 1;
}

int pertence(LISTA_ENC *pl, int valor){
	NODO* aux;
	aux = (NODO *) malloc (sizeof(NODO));
	aux = *pl;
	while(aux->next){
		if (aux->inf == valor){
			printf ("\no numero %d pertence a lista!\n", aux->inf);
			return 1;
		}
		aux = aux->next;	
	}
	printf("valor n encontrado!\n");
	return 0;
}
void imprimi_lista(LISTA_ENC *pl){
	NODO* aux = (NODO *) malloc (sizeof(NODO));

		for(aux = *pl;aux;aux=aux->next){
			printf ("%d \n",aux->inf);
		}
		printf ("\n");
		
	
}

void cria_lista (LISTA_ENC *pl){
*pl=NULL;

}

int eh_vazia (LISTA_ENC l){
	if (l == NULL){
		printf ("Eh Vazia!\n");
		return (l == NULL);
	}else{
		return 0;
	}
}

int tam (LISTA_ENC l){
int cont;
for (cont=0; l!= NULL; cont++)
l = l->next;
return (cont);
}

void ins (LISTA_ENC *pl, int v, int k){
NODO *novo;
if (k < 1 || k > tam(*pl)+1)
{
printf ("\nERRO! Posição invalida parainsercao.\n");
exit (1);
}
novo = (NODO *) malloc (sizeof(NODO));
if (!novo) { printf ("\nERRO! Memoria insuficiente!\n");
exit (2); 
}

novo->inf = v;
if (k==1){
novo->next = *pl;

*pl = novo;
 
}else{
LISTA_ENC aux;
for (aux=*pl; k>2; aux=aux->next, k--);

novo->next = aux->next;
aux->next = novo;
}
}
