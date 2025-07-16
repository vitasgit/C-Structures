#include "findunit.h"
#include <stdio.h>
#include <stdlib.h>

/*
 общее количество итераций поиска,
 обнуляется и заполняется каждой функцией поиска
*/  
int find_count;

/*
 Тип тест-функции
 Для линейного поиска должна возвращать 0 или 1
 (0 - переданный элемент НЕ соответствует критериям поиска, 1 - соответствует)
 Для бинарного поиска должна возвращать 0, 1 или -1
 (0 - переданный элемент соответствует критериям поиска; 
  1,-1 - больше/меньше искомого элемента или наоборот в зависимости от решения программиста)
*/

 typedef int (*testfunc)(int);

/*
 Линейный поиск одного элемента в целочисленном массиве
 возвращает индекс найденного значения или -1
 Параметры:
 src - исходный массив
 src_size - кол-во элементов в src
 func - тест-функция
*/
int line_find_one(const int src[], int src_size, testfunc func)
{
	find_count = 0;
	for (int i = 0; i < src_size; i++) {
		find_count++;
        if (func(src[i]) == 1) {
			//printf("fc = %d\n", find_count);
            return i;
        }
        //printf("%d\n", func(src[i]));
    }
    return -1;
}

/*
 Линейный поиск всех элементов в целочисленном массиве
 возвращает количество найденных элементов или 0
 Параметры:
 src - исходный массив
 src_size - кол-во элементов в src
 func - тест-функция
 result - массив найденных индексов
 result_maxsize - максимальное кол-во элементов в result
*/  
int line_find_all(const int src[], int src_size,  testfunc func, 
			      int result[], int result_maxsize)
{
	find_count = 0;
	int count = 0;
	int k = 0;
	for (int i = 0; i < src_size; i++) {
		find_count++;

		if (func(src[i]) == 1) {
			count++;

			if (k < result_maxsize) {
				result[k] = i;
				k++;
			}
		}
	}
	
	// printf("fc = %d\n", find_count);
	return count;
}


/*
 Бинарный поиск одного элемента в целочисленном массиве
 возвращает индекс найденного значения или -1
 Параметры:
 src - исходный массив
 src_size - кол-во элементов в src
 func - тест-функция
 // 1 2 3 4 5 6 7 8 9 10
*/  
int bin_find_one(const int src[], int src_size, testfunc func)
{
	find_count = 0;
	int l = 0;
	int r = src_size - 1;

	while (l <= r) {
		find_count++;
		int m = (l + r) / 2;
		int t = func(src[m]);

		if (t == 0) {
			//printf("fc = %d\n", find_count);
			return m;
		}
		if (t < 0) l = m + 1;
		if (t > 0) r = m - 1;
	}
	//printf("fc = %d\n", find_count);
	return -1;
}


/*
 Бинарный поиск всех элементов в целочисленном массиве
 возвращает количество найденных элементов или 0
 Параметры:
 src - исходный массив
 src_size - кол-во элементов в src
 func - тест-функция
 res_beg - адрес переменной, куда будет сохранен индекс первого найденного элемента
 res_end - адрес переменной, куда будет сохранен индекс последнего найденного элемента
*/  
int bin_find_all(const int src[], int src_size, testfunc func,
			      int *res_beg, int *res_end);

/*
 тест-фукнции
 Для линейного поиска должна возвращать 0 или 1
 (0 - переданный элемент НЕ соответствует критериям поиска, 1 - соответствует)

 Для бинарного поиска должна возвращать 0, 1 или -1
 (0 - переданный элемент соответствует критериям поиска; 
  1,-1 - больше/меньше искомого элемента или наоборот в зависимости от решения программиста)
*/

int test0(int x)
{
	return (x == -3);
}

int test1(int x)
{
	return (x == 3);
}

int test2(int x)
{
	return (x > 3);
}

int test3(int x)
{
	return (x - 1);  // ищем  1
}

int test4(int x)
{
	return (x % 2 == 0);
}