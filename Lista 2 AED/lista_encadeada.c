#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA, int x);
void insereInicio(node *LISTA, int x);
node * busca (node *LISTA, int x, node ** ant);
int retirar(node *LISTA, int x);
void exibe(node *LISTA);
void libera(node *LISTA);
void contador(node *LISTA);
void exibeinverso(node *LISTA);
void encontravalores(node *LISTA);


int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA);
	int opt;
	
	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt!=9);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	LISTA->num = NULL;
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
    printf("9. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
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
			contador(LISTA);
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
		printf("Lista vazia!\n\n");
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

void contador(node *LISTA)	//Exercicio 1 lista 2
{
    int cont = 0;
    node *ptr;
    ptr = LISTA->prox;

	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

    while(ptr != NULL){
       cont++;
       ptr = ptr->prox;  
    }
    if( cont == 0){
        printf("Nao ha elementos na lista\n");
    }
    else{
        printf("Numero de elementos: %d\n", cont);
    }
	
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

void encontravalores(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	int maior = tmp->num;
	int menor = tmp->num;
	int soma;

	
	
	while( tmp->prox != NULL){
		tmp = tmp->prox;
		if(tmp->num > maior){
			maior = tmp->num;
		}
		if(tmp->num < menor){
			menor = tmp->num;
		}

	}

	printf("Maior: %d \n", maior);
	printf("Menor: %d \n", menor);

	printf("\n\n");
}
