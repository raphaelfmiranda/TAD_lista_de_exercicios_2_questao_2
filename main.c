#include "listaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct lista_cfg lista;
    int choice;
	int nDigitado;
	int maior_valor_na_lista;
	float media;



    while(1)
	{
		printf(	"										\n"
			   	"======================================	\n"
			   	"\t\tM E N U							\n"
			   	"======================================	\n"
			   	"1. Inicializar a lista					\n"
			   	"2. Verificar se lista eh vazia			\n"
			   	"3. Verificar se lista eh cheia. 		\n"
			   	"4. Inserir elemento. 					\n"
			   	"5. Remover elemento. 					\n"
			   	"6. Mostrar tamanho da lista. 			\n"
			   	"6. Mostrar maior valor na lista. 		\n"
			   	"7. Mostrar media dos elementos.		\n"
			   	"8. Imprimir a lista. 					\n"
			   	"9. Sair 								\n"
				"======================================	\n"
			   ">>> Digite a opcao desejada: ")        	;	scanf("%d", &choice);



        switch(choice)
		{
			case (1):
				lista_inicializar(&lista)	;	printf("\n Lista inicializada!\n")	;	break;
			


			case (2):
				if(lista_esta_vazia(&lista))
				{
 					printf("A lista esta vazia.\n");
				}
				else
				{
					printf("A lista nao esta vazia.\n");
				}
				break;
			


			case (3):
				if(lista_esta_cheia(&lista))
				{
					printf("A lista esta cheia.\n");
				}
				else
				{
					printf("A lista nao esta cheia.\n");
				}
				break;
			


			case (4):
				printf("Digite o valor para insercao: ")	;	scanf("%d",&nDigitado);
				if (lista_insere_elemento(&lista , nDigitado))
				{
					printf("%d foi inserido na lista.\n" , nDigitado);
				}
				else
				{
					printf("Erro ao inserir valor. Tente Novamente\n");
				}
				break;
			


			case (5):
				printf("\n Digite o valor que deseja remover: ")	;	scanf("%d",&nDigitado);
				if (lista_remover_elemento(&lista , nDigitado))
				{
					printf("%d foi removido." , nDigitado);

					print_lista(&lista);
				}
				else
				{
					printf("Erro ao remover valor. Tente novamente.");
				}
				break;
			


			case (6):
				if(lista_encontrar_maior_elemento(&lista , &maior_valor_na_lista))
				{
                    printf("O maior valor da lista e: %d" , maior_valor_na_lista);
				}
                else
				{
                    printf("Nao existe maior valor na lista e/ou esta vazia.");
				}
                break;



			case (7):
				if(lista_media_aritmetica(&lista , &media))
				{
                    printf("Media: %5.2f\n" , media);
				}
                else
				{
                   printf("Nao ha valores para calculo de media.");
				}
                break;



			case (8):
				print_lista(&lista)		;	break;



			case (9):
				printf(	"										\n"
			   			"======================================	\n"
						">>> Voce encerrou o programa.			\n"
						"======================================	\n")	;	exit(1);
			


			default:
				printf(	"										\n"
			   			"======================================	\n"
						"A opcao digitada nao existe			\n"
						"======================================	\n")	;	break;
        }
    }
	return 0;
}