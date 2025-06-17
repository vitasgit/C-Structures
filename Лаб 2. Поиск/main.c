#include "findunit.h"
#include <stdio.h>
#define N 7

void printArr(const int *parr, int size);
void printTest(const int *parr, int size, testfunc func);


int main()
{
    int arr[N] = {1, 2, 3, 3, 5, 4, 7};
    printArr(arr, N);

    int i = line_find_one(arr, N, test2);
    // printf("i = %d\n", i);

    // printTest(arr, 5, test3);

    int res[5];
    int count = line_find_all(arr, N, test0, res, 5);
    printf("count = %d\n", count);

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