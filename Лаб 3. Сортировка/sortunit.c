#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>


/*
Функция сравнения
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  

*(const int *)pa  // сначала преобразовали указатель из типа void в тип const int, затем разыменовали и записали значение в переменную int a
*/
int cmp(const void * pa, const void * pb)
{
	int a = *(const int *)pa;
    int b = *(const int *)pb;

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
	printf("awdwad\n");
}
