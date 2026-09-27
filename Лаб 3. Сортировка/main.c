#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10

void outArr(const int *parr, int size);


int main()
{
    int arr[N] = {1, 6, 3, 3, 5, 4, 5, 9, 8, 5};
    //outArr(arr, N);
    //sort_bubble(arr, N, sizeof(arr[0]), cmp);
    //outArr(arr, N);

    // проверка cmp
    // int a = 5;
    // int b = -5;
    // int res = cmp(&a, &b);
    // printf("res = %d\n", res);

    
    // Вставками базовая
    sort_v(arr, N, sizeof(arr[0]), cmp);



    return 0;
}


void outArr(const int *parr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", parr[i]);
	}
    printf("\n");
}
