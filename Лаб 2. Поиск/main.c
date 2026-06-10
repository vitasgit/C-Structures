#include "findunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define SIZE 300000001       // 109 сек
//#define SIZE 200000001     // 69 сек
//#define SIZE 100000001     //  33 сек

void printArr(const int *parr, int size);

void lin_test(testfunc tfunc, char *fname);
void bin_test(testfunc tfunc, char *fname);

int test1(int x);
int test1_bin(int x);

int test2(int x);
int test2_bin(int x);

int test3(int x);
int test3_bin(int x);

int test_num(int x);
int test_bnum(int x);
int test_even(int x);  // четные

// проверить и переписать
//void printTest(const int *parr, int size, testfunc func);

// функция сравнения для qsort
int cmp(const void *a, const void *b);


//int arrvar[SIZE];
//int arrvar2[SIZE];  // не сортируемый
int *arrvar = NULL;
int *arrvar2 = NULL;

int main()
{
    clock_t start_tick, end_tick;
    double elapsed_time;
    arrvar = malloc(SIZE * sizeof(int));
    arrvar2 = malloc(SIZE * sizeof(int));

    
    for (int i=0; i < SIZE; i++) {
        //arrvar[i] = rand() % SIZE;
        arrvar2[i] = rand() % SIZE;
    }
    
    //printArr(arrvar, SIZE);
    //qsort(arrvar, SIZE, sizeof(int), cmp);
    
    /*
    start_tick = clock();
    qsort(arrvar, SIZE, sizeof(int), cmp);
    end_tick = clock();
    elapsed_time = (double)(end_tick - start_tick) / CLOCKS_PER_SEC;
    printf("Время qsort: %.2f секунд\n\n", elapsed_time);
    */

    FILE *f = fopen("nums2.txt", "rb");
    //fwrite(arrvar, sizeof(int), SIZE, f);
    fread(arrvar, sizeof(int), SIZE, f);
    printArr(arrvar, 100);


    printf("================= Сортированный ===================\n");
    printf("[0] = %d\n", arrvar[0]);
    printf("[(SIZE-1)/2] = %d\n", arrvar[(SIZE-1)/2]);
    printf("[SIZE-1] = %d\n\n", arrvar[SIZE-1]);

    lin_test(test1, "test1");
    bin_test(test1_bin, "test1_bin");

    lin_test(test2, "test2");
    bin_test(test2_bin, "test2_bin");

    lin_test(test3, "test3");
    bin_test(test3_bin, "test3_bin");

    printf("================= НЕ сортированный ===================\n");
    printf("[0] = %d\n", arrvar2[0]);
    printf("[(SIZE-1)/2] = %d\n", arrvar2[(SIZE-1)/2]);
    printf("[SIZE-1] = %d\n\n", arrvar2[SIZE-1]);
    lin_test(test1, "test1");
    lin_test(test2, "test2");
    lin_test(test3, "test3");


    printf("================= resarr ===================\n");
    printf("линейный\n");
    int lenres = 10;
    int resarr[lenres];
    int count = line_find_all(arrvar, SIZE, test_num, resarr, lenres);
    
    if (count > lenres) count = lenres;
    printf("count = %d\n", count);
    printArr(resarr, count);

    printf("\nбинарный\n");
    int res_beg = -1; 
    int res_end = -1;
    int bcount = bin_find_all(arrvar, SIZE, test_bnum, &res_beg, &res_end);
    printf("bcount = %d\n", bcount);
    printf("res_beg = %d\n", res_beg);
    printf("res_end = %d\n", res_end);

    free(arrvar);
    free(arrvar2);

    // старые тесты
    /*
    int arr[N] = {1, 6, 3, 3, 5, 4, 5, 9, 8, 5};
    int res_beg = -1; 
    int res_end = -1;
    printArr(arr, N);
    qsort(arr, N, sizeof(int), cmp);
    printArr(arr, N);

    printf("i = %d\n", line_find_one(arr, N, test1));
    printf("c = %d\n", find_count);

    printf("i = %d\n", bin_find_one(arr, N, test3));
    printf("c = %d\n", find_count);
    */

    //printTest(arr, N, test1);

    // int res[6];
    // int count = line_find_all(arr, N, test3, res, 6);
    // printf("count = %d\n", count);
    // printArr(res, 6);

    // int i = bin_find_one(arr, N, test3);
    // printf("i = %d\n", i);

    // int count = bin_find_all(arr, N, test3, &res_beg, &res_end);
    // printf("count = %d\n", count);
    // printf("res_beg = %d\n", res_beg);
    // printf("res_end = %d\n", res_end);



    return 0;
}


void printArr(const int *parr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", parr[i]);
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

void lin_test(testfunc tfunc,  char *fname)
{
    clock_t start_tick, end_tick;
    double elapsed_time;

    start_tick = clock();
    int i = line_find_one(arrvar, SIZE, tfunc);
    end_tick = clock();

    elapsed_time = (double)(end_tick - start_tick) / CLOCKS_PER_SEC;
    printf("%s - линейный\n", fname);
    printf("i = %d\n", i);
    printf("Итерации: %d\n", find_count);
    printf("Время: %.6f секунд\n", elapsed_time);
    printf("\n");
    //printf("-----------------\n\n", elapsed_time);
}

void bin_test(testfunc tfunc, char *fname)
{
    clock_t start_tick, end_tick;
    double elapsed_time;

    start_tick = clock();
    int i = bin_find_one(arrvar, SIZE, tfunc);
    end_tick = clock();

    elapsed_time = (double)(end_tick - start_tick) / CLOCKS_PER_SEC;
    printf("%s - бинарный\n", fname);
    printf("i = %d\n", i);
    printf("Итерации: %d\n", find_count);
    printf("Время: %.6f секунд\n", elapsed_time);
    printf("\n-----------------\n\n");
}


int test1(int x)
{
    return (x == arrvar[0]);
}

int test1_bin(int x)
{
    if (x == arrvar[0]) 
		return 0;
	else if (x > arrvar[0]) 
		return -1;
	else 
		return 1;
}

int test2(int x)
{
    return (x == arrvar[(SIZE-1)/2]);
}

int test2_bin(int x)
{
    if (x == arrvar[(SIZE-1)/2])
		return 0;
	else if (x > arrvar[(SIZE-1)/2])
		return -1;
	else
		return 1;
}

int test3(int x)
{
    return (x == arrvar[SIZE-1]);
}

int test3_bin(int x)
{
    if (x == arrvar[SIZE-1]) 
		return 0;
	else if (x > arrvar[SIZE-1]) 
		return -1;
	else 
		return 1;
}

int test_num(int x)
{
    return (x == 12);
}

int test_bnum(int x)
{
    if (x == 12) 
		return 0;
	else if (x > 12)
		return -1;
	else 
		return 1;
}

int test_even(int x)
{
    return (x%2 == 0);
}



// Преобразование неопределенного указателя к указателю типа int*
// и получение значения
// int cmp(const void *px, const void *py) 
//{
//   int x = *(int *)px;
//   int y = *(int *)py;

//   if (x > y) return 1;
//   if (x < y) return -1;
//   return 0;  
// }

/*
void printTest(const int *parr, int size, testfunc func)
{
    for (int i = 0; i < size; i++) {
        if (func(parr[i]) == 1) {
			printf("%d ", parr[i]);
        }
    }
    printf("\n");
}
*/