#define MAX 5
typedef struct{
int N; /*numero de elementos*/
int val[MAX]; /*vetor de elementos*/
int order; /*auxiliar para verificar se a lista e ordenada*/
}LISTA;

void remove_com_base_no_valor (LISTA *, int);
void insere_ordenado (LISTA *, int);
void Sair();
void gera_lista(LISTA *, int , int );
int ordenar_lista (LISTA *);
void cria_lista (LISTA *);
int eh_vazia (LISTA *);
int tam (LISTA *);
void imprimi (LISTA *);
void ins (LISTA *, int, int);
int recup (LISTA *, int);
void ret (LISTA *, int);
int pertence (LISTA *, int);
