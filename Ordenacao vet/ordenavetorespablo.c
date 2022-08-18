#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 1000000 //Pode ser definido valor acima de 1 milhao

double bubblesort(int vet[MAX], int n){
    int i, j;
    int aux = 0;
    double time_spent = 0.0;

    clock_t begin = clock();

    for(j = n - 1; j > 0; j--){    
        for(i = 0; i < j; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("O algoritmo bubblesort ordenou o vet[%d] em: %fs\n", n, time_spent); 

    return time_spent;

}

double insertsort(int vet[MAX], int n){
    int i, j, aux;
    double time_spent = 0.0;

    clock_t begin = clock();

    for (i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
    
        while ((j>=0) && (aux < vet[j])){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = aux;
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("O algoritmo insertionsort ordenou o vet[%d] em: %fs\n", n, time_spent);
    
    return time_spent;
}


double selectsort(int vet[MAX], int n){
    int i, j, min, aux;
    double time_spent = 0.0;

    clock_t begin = clock();

    for (i = 0; i < (n-1); i++) {
        min = i;

        for (j = (i+1); j < n; j++){
            if(vet[j] < vet[min]){
                min = j; 
            } 
        }   
               
        if(i != min){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux; 
        }
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("O algoritmo insertionsort ordenou o vet[%d] em: %fs\n", n, time_spent);
   
    return time_spent;
}

double shellsort(int *vet, int n) {
    int i , j , value;
    int gap = 1;
    double time_spent = 0.0;

    clock_t begin = clock();
    
    while(gap < n) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("O algoritmo shellsort ordenou o vet[%d] em: %fs\n", n, time_spent);

    return time_spent;
}

void q_sort(int vet[MAX], int left, int right){
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vet[(left + right) / 2];
     
    while(i <= j) {
        while(vet[i] < x && i < right) {
            i++;
        }
        while(vet[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        q_sort(vet, left, j);
    }
    if(i < right) {
        q_sort(vet, i, right);
    }   
}

double quicksort(int vet[MAX], int n){   
    int i;

    double time_spent = 0.0;
    clock_t begin = clock();
    q_sort(vet, 0, n);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("O algoritmo quicksort ordenou o vet[%d] em: %fs\n", n, time_spent);

    return time_spent;    
}

void mistura(int vet[MAX] ,int n){
    int i;

    srand(time(NULL));

    for(i=0; i<n; i++){
        vet[i] = rand();
    }

}

void sortarray(int vet[MAX]){
   
    int n;
    printf("Entre com o tamanho do vetor: \n");
    scanf("%d", &n);
    
    printf("\nOrdenando um vetor de tamanho %d \n", n);
    
    double timebubble, timeselect, timeinsert, timeshell, timequick;

    mistura(vet , n);
    
    timebubble = bubblesort(vet, n);
    mistura(vet , n);
    timeselect = selectsort(vet, n);
    mistura(vet , n);
    timeinsert = insertsort(vet, n);
    mistura(vet , n); 
    timeshell = shellsort(vet, n); 
    mistura(vet , n); 
    timequick = quicksort(vet, n);
   
    
         
}

void options(int op, int vet[MAX]){
    
    switch (op)
    {
    case 1:
        sortarray(vet);
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

int menu(void)
{
	int opt;
	
    printf("--------------------------------------------------------------\n");
	printf("|   Escolha a opcao:                                         |\n");
	printf("|   1 - Inserir tamnho do vetor(ate um milhao)               |\n");
    printf("|   2 - Sair                                                 |\n");
    printf("--------------------------------------------------------------\n\n");
    printf("Opcao: "); scanf("%d", &opt);
    
	
	return opt;
}


void main()
{
    int opt;
    int *vet;
    vet = (long int *) malloc(MAX*sizeof(long int));

	do{
		opt=menu();
		options(opt, vet);
	}while(opt!=2);

}
