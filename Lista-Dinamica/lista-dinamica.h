typedef struct nodo
{
int inf;
struct nodo * next;
}NODO;
typedef NODO * LISTA_ENC;


void remove_com_base_no_valor(LISTA_ENC *, int);
LISTA_ENC insere_ordenado(LISTA_ENC*, int);
void gera_lista(LISTA_ENC*, int , int );
int eh_ordenada(LISTA_ENC *);
int pertence(LISTA_ENC *, int);
void imprimi_lista(LISTA_ENC *);
void cria_lista (LISTA_ENC *);
int eh_vazia (LISTA_ENC);
int tam (LISTA_ENC);
void ins (LISTA_ENC *, int, int);
int recup (LISTA_ENC, int);
void ret (LISTA_ENC *, int);
