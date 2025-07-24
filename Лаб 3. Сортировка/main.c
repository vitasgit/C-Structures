#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10


int main()
{
    int arr[N] = {1, 6, 3, 3, 5, 4, 5, 9, 8, 5};
    bubble_sort(arr, N, sizeof(arr[0]), cmp);
    return 0;
}