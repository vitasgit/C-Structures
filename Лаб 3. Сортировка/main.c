#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 100

// n - кол-во элементов
void outArrInt(int *parr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", parr[i]);
	}
    printf("\n");
}

void outArrFloat(float *parr, int n)
{
    for (int i = 0; i < n; i++) {
		printf("%.2f ", parr[i]);
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

void *arrGenFloat(int n)
{
    float *parr = malloc(sizeof(float)*n);  // в куче
    for (int i=0; i < n; i++) {
        parr[i] = (float)rand() / (float)RAND_MAX * n;  // разобрать потом
    }

    return parr;
}

// int isSortedInt(int *parr, int n)
// {
//     for (int i=0; i<n-1; i++) {
//         if (parr[i] > parr[i+1]) return 0;
//     }
//     return 1;
// }

int isSorted(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
    if (nmemb < 2) return 1; // на пустой
    char *pprev = (char*)base;
    char *pnext = (char*)base + size;

    for (int i=0; i<nmemb-2; i++) {
        if (compar(pprev, pnext) > 0) return 0;
        pprev+= size; pnext+= size;
    }
    return 1;
}

//int goTests() {}

int main()
{
    float *parr = arrGenFloat(N);

    outArrFloat(parr, N);
    printf("isSorted=%d\n", isSorted(parr, N, sizeof(parr[0]), cmpFloat));

    sort_bubble(parr, N, sizeof(parr[0]), cmpFloat);
    outArrFloat(parr, N);
    printf("isSorted=%d\n", isSorted(parr, N, sizeof(parr[0]), cmpFloat));

    
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
