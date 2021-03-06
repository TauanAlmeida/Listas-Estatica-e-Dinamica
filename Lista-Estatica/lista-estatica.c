#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "lista-estatica.h"

int main(){
	int v,i,elem, m, n;
	char opcao;
	LISTA l;
	cria_lista (&l);
	eh_vazia (&l);
	for (i=1;i < 6;i++){
		printf ("valor para a lista: ");
		scanf ("%d", &v);
	//	ins (&l, v, i);  //insere a lista normal
	insere_ordenado (&l, v); //insere a lista ordenada
	}
	system("cls");
	while(opcao != 's' && 'S'){
		printf("Lista Estatica!\n");
		printf("(A) Ver Tamanho.\n");
		printf("(B) Consulta Lista.\n");
		printf("(C) Ver se eh Ordenada.\n");
		printf("(D) Retirar Elemento.\n");
		printf("(E) Ordenar Lista.\n");
		printf("(F) Consulta por valor.\n");
		printf("(G) Inserir Lista(M..N).\n");
		printf("(H) Imprimir Lista.\n");
		printf("(I) Remocao por valor.\n");

		fflush(stdin);
        opcao= getch(); 
        switch (opcao){
	
		case 'A':
	    case 'a':
	    	system("cls");
	    	tam (&l);
	    	system("pause");
	    	system("cls");
		break;
		
		case 'B':
	    case 'b':
	    	system("cls");
	    	printf ("Qual elemento?: ");
	    	scanf("%d", &elem);
	        printf ("No elemento %d tem o valor: %d\n",elem, recup (&l, elem));
	        system("pause");
	        system("cls");
		break;
		
		case 'C':
		case 'c':
			system("cls");
			eh_ord (&l);
			system("pause");
			system("cls");
		break;
		
		case 'D':
		case 'd':
			system("cls");
			printf ("Qual elemento da lista deseja retirar? ");
			scanf("%d", &elem);
			ret (&l, elem);
			system("pause");
			system("cls");
		break;
		case 'E':
		case 'e':
			system("cls");
			ordenar_lista(&l);
			system("pause");
			system("cls");
		break;
		
		case 'F':
		case 'f':
			system("cls");
			printf("Digite um numero: ");
			scanf ("%d", &elem);
			pertence (&l, elem);
			system("pause");
			system("cls");
		break;
		
		case 'g':
		case 'G':
			system("cls");
			printf("Digite um numero: ");
			scanf ("%d", &m);
			scanf ("%d", &n);
			gera_lista(&l, m, n);
			system("pause");
			system("cls");
		break;
		
		case 'h':
		case 'H':
			system("cls");
			imprimi(&l);
			system("pause");
			system("cls");
		break;
		
		case 'i':
		case 'I':
			system("cls");
			printf("Digite um numero: ");
			scanf ("%d", &elem);
			remove_com_base_no_valor (&l, elem);
			system("pause");
			system("cls");
		break;
		
		case 'S':
		case 's':
			system("cls");
			Sair();
		break;	
		default:
			system ("cls");
	}
	}

}

void Sair(){
	exit(1);
}

void gera_lista(LISTA *l, int m, int n){
	int i;
	if (l->N == MAX){
		printf ("\nERRO! Estouro na lista.\n");
		exit (1);
	}
	for (i=0;m<=n && l->N != MAX;m++){
		l->val[i]=m;
		l->N++;
		i++;
	}
}


int ordenar_lista (LISTA *l){
	int i,j, ord=0, aux;
	if (l->order == 1){
		printf ("Esta lista ja eh ordenada!\n");
		return 1;
	}
	for (j=0; j<l->N;j++){
		for (i=0; i<l->N;i++){
			if (l->val[i] > l->val[i+1]){
			aux = l->val[i];
			l->val[i] = l->val[i+1];
			l->val[i+1] = aux;
			}
		}
	}printf("Lista Ordenada: ");
	for (i=0; i<l->N;i++)printf(" %d ", l->val[i]);printf("\n");
}

void imprimi (LISTA *l){
	int i;
	for (i=0;i<l->N;i++){
		printf ("Lista[%d]: %d\n",i, l->val[i]);
	}
}
int eh_ord (LISTA *l){
	int i, ord=0;
	for(i=0;i<l->N;i++){
		if (l->val[i]<l->val[i+1]){
			ord++;
			if (ord == l->N-1){
				printf ("eh ordenada! %d\n", l->N-1);
				l->order=1;
			return 1;
			}
		}
	}
	printf ("nao eh ordenada!\n");
	return 0;
}

void cria_lista (LISTA *l){
l->N = 0;
}

int eh_vazia (LISTA *l){
return (l->N == 0);
}

int tam (LISTA *l){
	printf ("o tamanho da lista eh: %d\n", l->N);
return (l->N);
}

void insere_ordenado (LISTA *l, int v){
int i,aux;
static int j=1;
	if (l->N == MAX){
		printf ("\nERRO! Estouro na lista.\n");
		exit (1);
	}
	if (j < 1 || j > l->N+1){
		printf ("\nERRO! Posi��o invalida para insercao.\n");
		exit (2);
	}
	l->val[j-1]=v;
		for (i=0;i<l->N;i++){
			if (l->val[j-1] < l->val[i]){
				aux = l->val[i]; 
				l->val[i] = l->val[j-1];
				l->val[j-1] = aux;
			}	
		}
	l->N++;
	j++;
}

void remove_com_base_no_valor (LISTA *l, int v){
	int i, valor_encontrado = 0;
	for (i=0;i<l->N;i++){
		if (l->val[i] == v){
			valor_encontrado = 1;
		}
		if (valor_encontrado == 1 && i < l->N-1){
			l->val[i] = l->val[i+1];
		}
	}
	l->N--;
}


void ins (LISTA *l, int v, int k){
int i;
	if (l->N == MAX){
		printf ("\nERRO! Estouro na lista.\n");
		exit (1);
	}else
	if (k < 1 || k > l->N+1){
		printf ("\nERRO! Posi��o invalida para insercao.\n");
		exit (2);
	}

	for (i=l->N; i>=k; i--)
	l->val[i]=l->val[i-1];
	l->val[k-1]=v;
	l->N++;
}

int recup (LISTA *l, int k){
	if (k < 1 || k > l->N){
		printf ("\nERRO! Consulta invalida.\n");
		exit (3);
	}else
	return (l->val[k-1]);
}

void ret (LISTA *l, int k){
int i;
	if (k < 1 || k > l->N){
		printf ("\nERRO! Posi��o invalida para retirada.\n");
		exit (4);
	}
	
	for (i=k-1; i<l->N; i++){
		l->val[i]=l->val[i+1];
	}
	printf ("Valor Lista[%d] = %d RETIRADO!\n", k-1, l->val[k-1]);
	
	l->N--;
}

int pertence (LISTA *l, int v){
int i;
for (i=0;i < l->N;i++){
	if (l->val[i] == v){
		printf ("Valor existente: Val[%d]=%d\n", i, l->val[i]);
		return 1;
	}
}
printf ("Valor N encontrado\n");
return 0;
}
