#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 100000000 // Pode ser definido valor acima de 1 milhao

struct no // codigo arvore binaria de busca
{
  int info;
  struct no *esq;
  struct no *dir;
};
typedef struct no no;

void pre_ordem(no *pt)
{
  printf("\n %d ", pt->info);
  if (pt->esq != NULL)
    pre_ordem(pt->esq);
  if (pt->dir != NULL)
    pre_ordem(pt->dir);
}

no *busca_arvore(no *pt, int x, int *f)
{

  if (pt == NULL)
  {
    *f = 0;
    return (NULL);
  }
  else if (pt->info == x)
  {
    *f = 1;
    return (pt);
  }
  else if (pt->info > x)
    if (pt->esq == NULL)
    {
      *f = 2;
      return (pt);
    }

    else
    {
      pt = pt->esq;
      busca_arvore(pt, x, f);
    }
  else if (pt->dir == NULL)
  {
    *f = 2;
    return (pt);
  }

  else
  {
    pt = pt->dir;
    busca_arvore(pt, x, f);
  }
}

no *insercao(no *pt, int x)
{

  no *pt1, *pt2;
  int f;
  pt1 = busca_arvore(pt, x, &f);

  if (f == 1)
  {
    return (NULL);
  }
  else
  {
    pt2 = malloc(sizeof(no));
    pt2->info = x;
    pt2->esq = NULL;
    pt2->dir = NULL;
    if (f == 0)
    {
      return (pt2);
      printf("\n 2 %d f= ", f);
    }
    else if (f == 2)
    {
      if (x < pt1->info)
        pt1->esq = pt2;
      else
        pt1->dir = pt2;
      return (pt2);
    }
  }
}

void q_sort(int vet[MAX], int left, int right)
{
  int i, j, x, y;

  i = left;
  j = right;
  x = vet[(left + right) / 2];

  while (i <= j)
  {
    while (vet[i] < x && i < right)
    {
      i++;
    }
    while (vet[j] > x && j > left)
    {
      j--;
    }
    if (i <= j)
    {
      y = vet[i];
      vet[i] = vet[j];
      vet[j] = y;
      i++;
      j--;
    }
  }

  if (j > left)
  {
    q_sort(vet, left, j);
  }
  if (i < right)
  {
    q_sort(vet, i, right);
  }
}

quicksort(int vet[MAX], int n)
{
  int i;

  double time_spent = 0.0;
  clock_t begin = clock();
  q_sort(vet, 0, n);
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("O algoritmo quicksort ordenou o vet[%d] em: %fs\n", n, time_spent);

}

void misturavet(int vet[], int n)
{
  printf("Inserindo %d elementos...\n");
  int i;
  double time_spent = 0.0;
  clock_t begin = clock();
  clock_t end;
  int num;

  srand(time(NULL));

  for (i = 0; i < n; i++)
  {
    if(i == n-1){
      end = clock();
      printf("Insira um numero para realizar o teste de busca posteriormente\n");
      scanf("%d",&num);
      vet[i] = num;
    }
    else{
      vet[i] = rand();
    }
  }
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("O algoritmo inseriu %d elementos em: %fs\n", n, time_spent);
}


double sortarray(int vet[])
{
  double time_total = 0.0;
  double time_spent = 0.0;
  double time_spent3 = 0.0;
  clock_t begin_t;
  clock_t end_t;
  clock_t begin2;
  clock_t end2;
  clock_t begin3;
  clock_t end3;

  printf("-----VETOR-----\n");

  int n;
  int num;
  int resultado;
  int i;

  printf("Entre com o tamanho do vetor: \n");
  scanf("%d", &n);
  begin_t = clock();
  begin3 = clock();
  misturavet(vet, n);
  end3 = clock();
  quicksort(vet, n);
  printf("Entre com o valor digitado anteriormente para realizar as buscas\n");
  begin2 = clock();
  scanf("%d",&num);
  end2 = clock();
  resultado = buscasequencial(vet, n, num);
  if(resultado == -1){
    printf("Elemento nao encontrado\n");
  }
  else{
    printf("Posicao do elemento no array: %d\n", resultado);
  }
  resultado = buscabinaria(vet, num, 0, n-1);
  if(resultado == -1){
    printf("Elemento nao encontrado\n");
  }
  else{
    printf("Posicao do elemento no array: %d\n", resultado);
  }
  end_t = clock();
  time_spent3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;
  time_spent += (double)(end2 - begin2) / CLOCKS_PER_SEC;
  time_total += (double)(end_t - begin_t) / CLOCKS_PER_SEC;

  return (time_total-time_spent-time_spent3);

}


double arvorebin(no *pt){
  printf("-----ARVORE-----\n");
  int elem;
  int i; 
  int n;
  int f;
  double time_spent = 0.0;
  double time_spent2 = 0.0;
  double time_total = 0.0;
  clock_t begin_t;
  clock_t end_t;
  clock_t begin;
  clock_t end;
  clock_t begin2;
  clock_t end2;
  no *aux;

  
  printf("Entre com a quanitadade desejada de elementos da arvore(Ate 1 bilhao)\n");
  scanf("%d", &n);

  srand(time(NULL));

  printf("\n Elemento:");
  begin_t = clock();
  
  begin = clock();
  for(i = 0; i < n; i++){
    if( i == n-1){
      printf("Entre com o elemento para ser buscado posteriormente\n");
      begin2 = clock();
      scanf("%d", &elem);
      end2 = clock();
    }
    else{
      elem = rand();
    }
    if (pt == NULL){
      pt = insercao(pt, elem);
    }
    else{
      insercao(pt, elem);
    }
  }
  end = clock();
  time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo de insercacao na ABB: %f\n", time_spent-time_spent2);
  time_spent = 0.0;
  printf("\n Elemento:");
  begin = clock();
  aux = busca_arvore(pt, elem, &f);
    if (f == 1){
      printf("\v %d f=  %d ELEMENTO ENCONTRADO !!! ", aux->info, f);
    }
    else{
      printf("\n ELEMENTO NAO ENCONTRADO !!!");
    }
  end = clock();
  printf("Tempo de busca na ABB: %f\n", time_spent);
  end_t = clock();

  time_total += (double)(end_t - begin_t) / CLOCKS_PER_SEC;

  return (time_total-time_spent2);

  // if (pt != NULL){
  //   pre_ordem(pt);
  // }
  // else{
  //   printf("\n ARVORE VAZIA !!! ");
  // }    
}


int buscasequencial(int a[], int n, int val)
{
  double time_spent = 0.0;
  clock_t begin = clock();
  clock_t end;
  for (int i = 0; i < n; i++){    
    if (a[i] == val){
      end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Tempo no algoritmo de busca sequencial: %f\n", time_spent);
      return i;
    }  
    
  }
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo no algoritmo de busca sequencial: %f\n", time_spent);  
  return -1;  
}  




int buscabinaria(int array[], int x, int low, int high)
{
  double time_spent = 0.0;
  clock_t begin = clock();
  clock_t end;


  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x){
      end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Tempo no algoritmo de busca sequencial: %f\n", time_spent);
      return mid;
    }

    if (array[mid] < x){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Tempo no algoritmo de busca sequencial: %f\n", time_spent);
  return -1;
}

  



void main()
{

  no *raiz = NULL; 
  int opt;
  int *vet;
  vet = (long int *)malloc(MAX * sizeof(long int));
  double tempo1 = 0.0, tempo2 = 0.0;

  while(opt != 2){
    printf("--------------------------------------------------------------\n");
    printf("|   Escolha a opcao:                                         |\n");
    printf("|   1 - Inserir tamanho(ate 1 bilhao)                        |\n");
    printf("|   2 - Sair                                                 |\n");
    printf("--------------------------------------------------------------\n\n");
    printf("AVISO ------- SO COLOQUE 1 BILHAO SE VC CONFIA NO SEU PROCESSADOR ------- AVISO\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      tempo1 = sortarray(vet);
      tempo2 = arvorebin(raiz);
      printf("\n\n");
      printf("Tempo no vetor: %f\n", tempo1);
      printf("Tempo na ABB: %f\n\n", tempo2);
      break;
    case 2:
      printf("See ya ;)");
      sleep(1);
      exit(1);
      break;
    default:
      printf("Comando invalido\n\n");
    }
  }
}
