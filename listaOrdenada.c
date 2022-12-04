#include "listaOrdenada.h"
#include <string.h>
#include <stdio.h>

//inicializa comprimento da lista como 0(zero)
void lista_inicializar(struct lista_cfg *lista)
{	
	lista -> cur_len_data = 0;
	
}

//retorna verdadeiro se a lista estiver cheia, caso contrário retornar falso
bool lista_esta_cheia(struct lista_cfg *lista){
	
	if(lista -> cur_len_data == MAX)
		return true;
	
	return false;
	
}

//retorna verdadeiro se a lista estiver vazia, caso contrário retornar falso
bool lista_esta_vazia(struct lista_cfg *lista){
	
	
	if(lista -> cur_len_data == 0)
		return true;
	
	return false;
	
}



//insere elemento na lista, retornar 1 se conseguiu inserir elemento, caso contrário retorna 0
int lista_insere_elemento(struct lista_cfg *lista , int elem_to_add){
	
	
	if(lista_esta_cheia(lista))
		return 0;
	
	
	int i;
	int qtd_elem_to_move;

	for(i = 0 ; i< lista -> cur_len_data ; i++){
		
		//abrir "espaço" se necessário para inserir o elemento na posição correta
		if(lista -> data[i] > elem_to_add){
			qtd_elem_to_move = sizeof(int) * (lista -> cur_len_data - i);
			memmove(lista -> data + i + 1, lista -> data + i, qtd_elem_to_move);//mover elementos a partir da posição que o novo elemento vai ser colocado,"1 casa" para frente
			break;
		}
		
	}
	
	lista -> data[i] = elem_to_add;
	lista -> cur_len_data += 1;

	return 1;
	
		
}

//remove elemento na lista, retornar 1 se conseguiu remover, caso contrário retorna 0
int lista_remover_elemento(struct lista_cfg *lista , int elem_to_remove){
	
	
	if(lista_esta_vazia(lista))
		return 0;

	//verifica se o elemento está presente na lista
	if(lista -> data[lista -> cur_len_data - 1] < elem_to_remove)
		return 0;

	int i;
	int qtd_elem_to_move;
	for(i = 0 ; i < lista -> cur_len_data ; i++){

		//elemento não está presente na lista
		if(lista -> data[i] > elem_to_remove)
			break;

		if(lista -> data[i] == elem_to_remove){
			qtd_elem_to_move = sizeof(int) * (lista -> cur_len_data - i - 1);
			memmove(lista -> data + i , lista -> data + i + 1 , qtd_elem_to_move); //mover elementos que estão na FRENTE do elemento que vai ser REMOVIDO, "1 casa" para trás
			lista -> cur_len_data -= 1;
			return 1;
		}

	}
	
	return 0;

	
	
}

/*
	armazena através do ponteiro(int *maior_valor_na_lista) o maior elemento da lista,
	se a lista estiver vazia retorna 0, caso contrário retorna 1
*/
int lista_encontrar_maior_elemento(struct lista_cfg *lista , int *maior_valor_na_lista){
	
	if(lista_esta_vazia(lista))
		return 0;
	

	*maior_valor_na_lista = lista -> data[lista -> cur_len_data - 1];//último elemento da lista sempre vai ser o maior, porque ela está ordenada


	return 1;
}



/*
	armazena através do ponteiro(int *media) a média aritmética dos números presentes na lista,
	se a lista estiver vazia retorna 0, caso contrário retorna 1
*/
int lista_media_aritmetica(struct lista_cfg *lista , float *media){


	if(lista_esta_vazia(lista))
		return 0;

	float sum = 0;
	int i;
	for(i = 0 ; i < lista -> cur_len_data ; i++){
		sum += lista -> data[i];
	}

	*media = sum / lista -> cur_len_data;

	return 1; 

}


void print_lista(struct lista_cfg *lista)
{	
	int i;
	
	printf(	"										\n"
			"======================================	\n"
			"# Impressao da lista: 					\n"
			"======================================	\n");

	for (i = 0 ; i < lista -> cur_len_data ; i++)
	{
		printf("# Lista [%d]: %d\n" , i , lista -> data[i]);
	}
}