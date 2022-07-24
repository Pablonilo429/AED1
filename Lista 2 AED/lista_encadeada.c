//Codigo feito pelo professor da UFRRJ Marcelo Dib Cruz
//As funcoes contador, exibeinverso, encontravalores, encontradois, maior, ordenalista e invertelista foram feitas por Pablo de Oliveira Araujo Xavier


#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

void inicia(node *LISTA);
void inicia(node *LISTA1);
int menu(void);
void opcao(node *LISTA, node *LISTA1, int op);
node *criaNo();
void insereFim(node *LISTA, int x);
void insereInicio(node *LISTA, int x);
node * busca (node *LISTA, int x, node ** ant);
int retirar(node *LISTA, int x);
void exibe(node *LISTA);
void libera(node *LISTA);
int contador(node *LISTA);
void exibeinverso(node *LISTA);
void encontravalores(node *LISTA);
void encontradois(node *LISTA);
int maior(node *LISTA);
void ordenalista(node *LISTA, node *LISTA1);
void invertelista(node *LISTA, node *LISTA1);
void exibe(node *LISTA1);


int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	node *LISTA1 = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA); inicia(LISTA1);
	int opt;
	
	do{
		opt=menu();
		opcao(LISTA,LISTA1,opt);
	}while(opt!=10);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	LISTA->num = NULL;		//A funcao encontra valores nao funciona sem definir essa variavel como NULL
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Retirar \n");
	printf("5. Zerar lista\n");
	printf("6. Contar Elementos\n");
	printf("7. Exibir Lista Inversa\n");
	printf("8. Encontrar\n");
	printf("9. Encontrar Dois Maiores Numeros\n");
	printf("10. Ordenar Lista\n");
	printf("11. Criar e Exibir Lista Inversa\n");
    printf("12. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, node *LISTA1, int op)
{   int x ;
	switch(op){	
			
		case 1:
			exibe(LISTA);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereInicio(LISTA,x);
			break;
		
		case 3:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereFim(LISTA,x);
			break;		
			
		case 4:
			printf("Novo elemento: "); 
		    scanf("%d", &x);
			retirar(LISTA,x);
			break;		
			
		case 5:
			libera(LISTA);
			break;
			
	    case 6:
			printf("Numero de elementos: %d\n", contador(LISTA));;
			break;
		case 7:
			exibeinverso(LISTA);
			printf("\n");
            break;
		case 8:
			encontravalores(LISTA);
			printf("\n");
			break;
		case 9:
			encontradois(LISTA);	
			break;
		case 10:
			ordenalista(LISTA, LISTA1);
			break;
		case 11:
			invertelista(LISTA, LISTA1);
			exibe(LISTA1);
			printf("\n");
			break;
		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


void insereFim(node *LISTA,int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	novo->prox = NULL;
	novo->num = x ;
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA, int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->num = x ;
	novo->prox = oldHead;
}

node * busca (node *LISTA, int x, node ** ant)
{ node *ptr ;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) return NULL ;
               else 
               { ptr = LISTA->prox;
                 while (ptr != NULL) 
                    { if (ptr->num != x) { *ant = ptr ;
                                           ptr = ptr->prox ;}
                         else 
                        {if (ptr->num == x)  return ptr ;
                                             else  return (NULL);	                     
                         break;
                        }
                     }
               }
}

int retirar(node *LISTA, int x)
{ node * ant ;
  node *aux = busca(LISTA, x, &ant);
  if (aux)  { ant->prox = aux->prox ;
           free(aux);
           return(1);
          } 
            else return 0 ;
 }     

void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

int contador(node *LISTA)	//Exercicio 1 lista 2
{
    int cont = 0;
    node *ptr;
    ptr = LISTA->prox;

	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

    while(ptr != NULL){			//Segue a mesma logica da funcao busca, porem percorre toda lista ate achar NULL no apontador
       cont++;
       ptr = ptr->prox;  
    }
    if( cont == 0){
        printf("Nao ha elementos na lista\n");
    }
   
	
	return cont;
}

void exibeinverso(node *LISTA)		//Exercicio 2 lista 2
{	

	if(LISTA == NULL){
		return;
	}
	
	exibeinverso(LISTA->prox);		
	if(LISTA->num != NULL){		
		printf("  %d", LISTA->num);
	}
}
int maior(node *LISTA){		//Complemento para o exercicio 3 e 5
	node *tmp;
	tmp = LISTA;
	int maior = tmp->num;
	while( tmp->prox != NULL){
		tmp = tmp->prox;
		if(tmp->num > maior){	//Acha o maior numero da lista
			maior = tmp->num;
		}
	}
	return maior;
}

void encontravalores(node *LISTA)	//Exercicio 3 lista 2
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	int soma = tmp->num;	//SEM ESSA DECLARACAO O SOMADOR NAO FUNCIONA
	int menor = tmp->num;
	float media;
	

	
	while( tmp->prox != NULL){
		tmp = tmp->prox;
		if(tmp->num < menor){	//Acha o menor numero da lista
			menor = tmp->num;
		}

		soma = soma + tmp->num;	//Soma dos elementos da lista
	}
	


	
	media = (float)soma/contador(LISTA); //Acessa a funcao contador para encontrar o numero de elementos

	printf("Maior: %d \n", maior(LISTA));
	printf("Menor: %d \n", menor);
	printf("Media: %.1f \n", media);

	printf("\n\n");



	
}

void encontradois(node *LISTA){		//Exercicio 4 lista 2

	node *tmp;
	tmp = LISTA->prox;
	int maior = tmp->num;
	int smaior = tmp->num;

	while( tmp->prox != NULL){
		tmp = tmp->prox;
		if(tmp->num > maior){
			maior = tmp->num;
		}
		if(tmp->num > smaior && tmp->num < maior){
			smaior = tmp->num;
		}
	}

	printf("Maior numero: %d\n", maior);
	printf("Segundo maior numero: %d\n", smaior);

}

void ordenalista(node *LISTA, node *LISTA1){	//Exercicio 5 lista 2
	int m = -1;

	if(vazia(LISTA)){
		printf("Lista vazia\n");
	}

	while(!vazia(LISTA)){
	  	m = maior(LISTA);
		insereInicio(LISTA1,m);
		retirar(LISTA, m);			 	
	}
	exibe(LISTA1);
}

void invertelista(node *LISTA, node *LISTA1)		//Exercicio 6 lista 2
{	

	if(LISTA == NULL){
		return;
	}
	
	exibeinverso(LISTA->prox);		
	if(LISTA->num != NULL){		
		LISTA1 = LISTA;
	}
}
