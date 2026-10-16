#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 100

// n - кол-во элементов
void outArr(const int *parr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", parr[i]);
	}
    printf("\n");
}

int cmpInt(const void *pa, const void *pb)
{
	int a = *( (int*)pa );  // Преобразование неопределенного указателя к указателю типа int*
    int b = *( (int*)pb );  // поменять для простоты на int b = *(int*)pb

	if (a > b) return 1;
	else if (a < b) return -1;
	return 0;

	//return a-b;
}

int cmpFloat(const void* pa, const void * pb)
{
    float a = *( (float*)pa );
    float b = *( (float*)pb );
    return (a > b) - (a < b);
    // сравнивать вещ числа напрямую нельзя.
    // в qsort 0 - значит числа равны (правирить в доке)
}

int ftest()
{
    printf("");
}

// генерирует массив и возвращает указатель
// глобальный счетчик 
// генерит int значения
// int *arrGenInt(int n)
// {
//     int arr[n];  // выделяется в стеке (баг)
//     for (int i=0; i < n; i++) {
//         arr[i] = rand() % n;
//     }

//     return arr;
// }

// генерирует массив и возвращает указатель
// генерит int значения
// size - размер ячейки, n - кол элементов
void *arrGenInt(int n)
{
    int *parr = malloc(sizeof(int)*n);  // в куче
    for (int i=0; i < n; i++) {
        parr[i] = rand() % n;  // parr[i] == *(parr+i)
    }

    return parr;
}

int isSorted(int *parr, int n)
{
    for (int i=0; i<n-1; i++) {
        if (parr[i] > parr[i+1]) return 0;
    }
    return 1;
}

//int goTests() {}

int main()
{
    int *parr = arrGenInt(N);

    outArr(parr, N);
    printf("isSorted=%d\n", isSorted(parr, N));

    sort_bubble(parr, N, sizeof(parr[0]), cmpInt);
    outArr(parr, N);
    printf("isSorted=%d\n", isSorted(parr, N));

    
    free(parr);

    // проверка cmp
    // int a = 5;
    // int b = -5;
    // int res = cmp(&a, &b);
    // printf("res = %d\n", res);

    
    // Вставками базовая
    //sort_v(arr, N, sizeof(arr[0]), cmp);



    return 0;
}
