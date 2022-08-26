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
    printf("inserao Invalida");
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
    vet[i] = rand();

  }
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("O algoritmo inseriu %d elementos em: %fs\n", n, time_spent);
}

void misturaarvore(no *pt, int n){
  int i;
  int num;
  int elem;
  double time_spent = 0.0;
  double time_spent2 = 0.0;
  clock_t begin = clock();
  clock_t end;
  clock_t begin2;
  clock_t end2;

  srand(time(NULL));

  for(i = 0; i < n; i++){
    elem = rand(); 
    if(i == n-1){
      printf("Insira um numero para realizar o teste de busca posteriormente\n");
      begin2 = clock();
      scanf("%d", &elem);
      end2 = clock();
      if (pt == NULL){
      pt = insercao(pt, elem);
      }
      else{
      insercao(pt, elem);
      }
    }
    else if (pt == NULL){
      pt = insercao(pt, elem);
    }
    else{
      insercao(pt, elem);
    }
    
  }
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
  printf("O algoritmo inseriu %d elementos em: %fs\n", n, time_spent2-time_spent);

}

void sortarray(int vet[])
{

  printf("-----VETOR-----\n");

  int n;
  int num;
  int busca;
  double time_spent = 0.0;
  
  printf("Entre com o tamanho do vetor: \n");
  scanf("%d", &n);

  misturavet(vet, n);
  quicksort(vet, n);
  printf("Entre com o valor digitado anteriormente para realizar as buscas\n");
  scanf("%d",&num);
  busca = buscasequencial(vet, n, num);
  if(busca == -1){
    printf("Elemento nao encontrado\n");
  }
  else{
    printf("Valor: %d\n", busca);
  }
  clock_t begin = clock();
  busca = buscabinaria(vet, 0, n-1, num);
  clock_t end = clock();
  if(busca == -1){
    printf("Elemento nao encontrado\n");
  }
  else{
    printf("Valor: %d\n", busca);
  }
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("O algoritmo busca binaria realizou a busca em: %fs\n",time_spent);

}

void arvorebin(no *pt){
  no *aux;
  int n;
  int elem;
  int f;
  double time_spent = 0.0;

  printf("-----ARVORE-----\n");

  printf("Entre com o numero de elementos da arvore: \n");
  scanf("%d", &n);
  misturaarvore(pt, n);
  printf("Entre com o valor digitado anteriormente para realizar as buscas\n");
  scanf("%d", &elem);
  clock_t begin = clock();
  aux = busca_arvore(pt, elem, &f);
  clock_t end = clock();
  if (f == 1){
    printf("%d f=  %d ELEMENTO ENCONTRADO !!!\n", aux->info, f);
  }
  else{
    printf("ELEMENTO NAO ENCONTRADO !!!\n");
  }
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("O algoritmo realizou a busca em: %fs\n",time_spent);
}


int buscasequencial(int vet[], int size, int val)
{
  double time_spent = 0.0;
  clock_t begin = clock();
  

  for (int i = 0; i < size; i++){
    if (vet[i] == val){
      return i;
    }
  
  return -1;
  }
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("O algoritmo busca sequencial realizou a busca em: %fs\n",time_spent);
}



int buscabinaria(int a[], int beg, int end, int val)
{
  double time_spent = 0.0;
  clock_t begin = clock();

  int mid;
  if (end >= beg)
  {
    mid = (beg + end) / 2;
    if (a[mid] == val)
    {
      return mid + 1;
    }
    
    else if(a[mid] < val)
    {
    return buscabinaria(a, mid+1, end, val);
    }
    
    else
    {
    return buscabinaria(a, beg, mid - 1, val);
    }
  }
  return -1;
}

void main()
{

  no *raiz = NULL; 
  int opt;
  int *vet;
  vet = (long int *)malloc(MAX * sizeof(long int));

  while(opt != 2){
    printf("--------------------------------------------------------------\n");
    printf("|   Escolha a opcao:                                         |\n");
    printf("|   1 - Inserir tamanho(ate um milhao)                       |\n");
    printf("|   2 - Sair                                                 |\n");
    printf("--------------------------------------------------------------\n\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
      sortarray(vet);
      arvorebin(raiz);


      printf("\n\n");
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
