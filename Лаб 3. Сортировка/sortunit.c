#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Функция сравнения
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  

*(const int *)pa  // сначала преобразовали указатель из типа void в тип const int, затем разыменовали и записали значение в переменную int a
*/
int cmp(const void * pa, const void * pb)
{
	int a = *(const int *)pa;  // Преобразование неопределенного указателя к указателю типа int*
    int b = *(const int *)pb; 

	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;

	return a - b;
}


/*
Сортировка пузырьком
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void bubble_sort(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	char *p0 = (char *)base;  // получить указатель на начало массива, на первый байт
	char *tmp = malloc(size);  // указатель типа char на область памяти в size байтах (size ячеек по 1 байту(char))
	
	for (int i = 0; i < nmemb-1; i++) {  // перебираем каждый элемент(индекс)
		bool flag = 0;

		for (int j = 0; j < nmemb-1; j++) {  // сравниваем соседние элементы(индексы)
		    
			void *a = p0+j*size;  // адрес на первую ячейку
			void *b = p0+(j+1)*size;  // адрес на следующую ячейку

			if (cmp(a, b) > 0) {
				memcpy(tmp, a, size);
				memcpy(a, b, size);
				memcpy(b, tmp, size);
				flag = 1;
			}
		}
		if (flag == 0) {break;}

	}
	free(tmp);
}


/*
Сортировка вставками базовая
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void insert_sort(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	printf("awdawd");
}
