#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10

void printArr(const int *parr, int size);


int main()
{
    int arr[N] = {1, 6, 3, 3, 5, 4, 5, 9, 8, 5};
    printArr(arr, N);
    bubble_sort(arr, N, sizeof(arr[0]), cmp);
    printArr(arr, N);

    // проверка cmp
    // int a = 5;
    // int b = -5;
    // int res = cmp(&a, &b);
    // printf("res = %d\n", res);



    return 0;
}


void printArr(const int *parr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", parr[i]);
	}
    printf("\n");
}