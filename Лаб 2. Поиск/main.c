#include "findunit.h"
#include <stdio.h>

void printArr(const int *parr, int size);
void printTest(const int *parr, int size, testfunc func);


int main()
{
    int arr[5] = {1, 2, 3, 5, 4};
    printArr(arr, 5);

    int i = line_find_one(arr, 5, test2);
    // printf("i = %d\n", i);

    printTest(arr, 5, test3);

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