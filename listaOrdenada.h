#include <stdbool.h>

#define MAX 10

struct lista_cfg
{	
	int data[MAX];
	int cur_len_data;	
};


void lista_inicializar(struct lista_cfg *lista);
bool lista_esta_vazia(struct lista_cfg *lista);
bool lista_esta_cheia(struct lista_cfg *lista);
int lista_insere_elemento(struct lista_cfg *lista , int elem_to_add);
int lista_remover_elemento(struct lista_cfg *lista , int elem_to_remove);
int lista_encontrar_maior_elemento(struct  lista_cfg *lista , int *maior_valor_na_lista);
int lista_media_aritmetica(struct lista_cfg *lista , float *media);
void print_lista(struct lista_cfg *lista);