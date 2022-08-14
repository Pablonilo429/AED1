#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void bubble_sort(int a[], int array_size)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j, tmp;

    for (i = 0; i < array_size; i++)
    {

        for (j = 0; j < (array_size - 1 - i); j++)
        {

            if (a[j + 1] < a[j])
            {

                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("O algoritmo bubblesort ordenou o vet[%d] em: %fs\n", array_size, time_spent);
}

void insertion_sort(int numbers[], int array_size)
{
    double time_spent = 0.0;
    clock_t begin = clock();

    int i, j, index;

    for (i = 1; i < array_size; i++)
    {
        index = numbers[i];
        j = i;
        while ((j > 0) && (numbers[j - 1] > index))
        {
            numbers[j] = numbers[j - 1];
            j = j - 1;
        }
        numbers[j] = index;
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("O algoritmo insertionsort ordenou o vet[%d] em: %fs\n", array_size, time_spent);
}

void selection_sort(int numbers[], int array_size)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j;
    int min, temp;

    for (i = 0; i < array_size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < array_size; j++)
        {
            if (numbers[j] < numbers[min])
                min = j;
        }
        temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("O algoritmo selectionsort ordenou o vet[%d] em: %fs\n", array_size, time_spent);
}

void shell_sort(int numbers[], int array_size)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j, increment, temp;

    increment = 3;
    while (increment > 0)
    {
        for (i = 0; i < array_size; i++)
        {
            j = i;
            temp = numbers[i];
            while ((j >= increment) && (numbers[j - increment] > temp))
            {
                numbers[j] = numbers[j - increment];
                j = j - increment;
            }
            numbers[j] = temp;
        }
        if (increment / 2 != 0)
            increment = increment / 2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("O algoritmo shellsort ordenou o vet[%d] em: %fs\n", array_size, time_spent);
}

void q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(numbers, left, pivot - 1);
    if (right > pivot)
        q_sort(numbers, pivot + 1, right);
}

void quick_sort(int numbers[], int array_size)
{   
    double time_spent = 0.0;
    clock_t begin = clock();
    q_sort(numbers, 0, array_size - 1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("O algoritmo quicksort ordenou o vet[%d] em: %fs\n", array_size, time_spent);
}
int mistura(int vet[], int array_size){      //Insere valores randomicos no vetor
    srand(time(NULL));
    for(int i = 0; i < array_size; i++){
        vet[i] = rand();
    }
    return vet;
}
void print(int vet[], int array_size){  
    for(int i = 0; i < array_size; i++){
        printf("%d  ", vet[i]);
    }
}

void sortarray_one(){
   
    printf("Ordenando um vetor de tamanho 1000\n");
   
    int vet[1000];
    
    mistura(vet, 1000);
    bubble_sort(vet,1000);
    mistura(vet, 1000);
    selection_sort(vet,1000);
    mistura(vet, 1000);
    insertion_sort(vet, 1000);
    mistura(vet, 1000);
    shell_sort(vet, 1000);
    mistura(vet, 1000);
    quick_sort(vet, 1000);

}

void sortarray_two(){
   
    printf("Ordenando um vetor de tamanho 10000\n");
   
    int vet[10000];
    
    
    mistura(vet, 10000);
    bubble_sort(vet,10000);
    mistura(vet, 10000);
    selection_sort(vet,10000);
    mistura(vet, 10000);
    insertion_sort(vet, 10000);
    mistura(vet, 10000);
    shell_sort(vet, 10000);
    mistura(vet, 10000);
    quick_sort(vet, 10000);

}

void sortarray_three(){
    printf("Ordenando um vetor de tamanho 100000\n");
   
    int vet[100000];
    
    mistura(vet, 100000);
    bubble_sort(vet,100000);
    mistura(vet, 100000);
    selection_sort(vet,100000);
    mistura(vet, 100000);
    insertion_sort(vet, 100000); 	
    mistura(vet, 100000);
    shell_sort(vet, 100000);
    mistura(vet, 100000);
    quick_sort(vet, 100000);

}



void options(int op){
    switch (op)
    {
    case 1:
        sortarray_one();
        printf("\n\n");
        
        break;
    case 2:
        sortarray_two();
        printf("\n\n");
        break;
    case 3:
        sortarray_three();
        printf("\n\n");
        break;
    case 4:
        printf("Byeee ;)");
        sleep(1);
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
	printf("|   1 - Ver o tempo de ordenacao no vetor de tamanho 1000   |\n");
	printf("|   2 - Ver o tempo de ordenacao no vetor de tamanho 10000  |\n");
    printf("|   3 - Ver o tempo de ordenacao no vetor de tamanho 100000 |\n");
    printf("|   4 - Sair                                                 |\n");
    printf("--------------------------------------------------------------\n");
    printf("Opcao: "); scanf("%d", &opt);
    
	
	return opt;
}



void main()
{
   int opt;
	
	do{
		opt=menu();
		options(opt);
	}while(opt!=4);

}
