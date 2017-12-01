#include <stdio.h>
#includle <stdlib.h>

int main(){
	
}

void cria_lista (LISTA_ENC *pl){
*pl=NULL;
}

int eh_vazia (LISTA_ENC l){
return (l == NULL);
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
}
else {
LISTA_ENC aux;
for (aux=*pl; k>2; aux=aux->next, k--);
novo->next = aux->next;
aux->next = novo;
}
}
