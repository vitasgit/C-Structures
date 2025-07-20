#include "findunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10

void printArr(const int *parr, int size);
void printTest(const int *parr, int size, testfunc func);

// функция сравнения для qsort
int cmp(const void *a, const void *b);


int main()
{
    int arr[N] = {1, 6, 3, 3, 5, 4, 5, 9, 8, 5};
    int res_beg = -1; 
    int res_end = -1;
    printArr(arr, N);
    qsort(arr, N, sizeof(int), cmp);
    printArr(arr, N);

    //int i = line_find_one(arr, N, test2);
    // printf("i = %d\n", i);

    // printTest(arr, 5, test3);

    // int res[6];
    // int count = line_find_all(arr, N, test3, res, 6);
    // printf("count = %d\n", count);
    // printArr(res, 6);

    // int i = bin_find_one(arr, N, test3);
    // printf("i = %d\n", i);

    int count = bin_find_all(arr, N, test3, &res_beg, &res_end);
    printf("count = %d\n", count);
    printf("res_beg = %d\n", res_beg);
    printf("res_end = %d\n", res_end);



    return 0;
}


void printArr(const int *parr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", parr[i]);
	}
    printf("\n");
}


void printTest(const int *parr, int size, testfunc func)
{
    for (int i = 0; i < size; i++) {
        if (func(parr[i]) == 1) {
			printf("%d ", parr[i]);
        }
    }
    printf("\n");
}


/*
(const int *)a - преобразовали указатель к типу const int 
f - first
s - second
*/
int cmp(const void *a, const void *b)
{
    const int *f = (const int *)a;
	const int *s = (const int *)b;
    if (*f > *s) return 1;
	if (*f < *s) return -1;
	return 0;
}