// заголовочный файл функций сортировки
#ifndef SORTUNIT
#define SORTUNIT
#include <stddef.h>


/*
Функция сравнения для сортировок
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  
*/
int cmp(const void * pa, const void * pb);


/*
Сортировка пузырьком
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void bubble_sort(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *));


/*
Сортировка вставками базовая
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void insert_sort(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *));


#endif // SORTUNIT
