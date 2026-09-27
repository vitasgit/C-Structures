// заголовочный файл функций сортировки
#ifndef SORTUNIT
#define SORTUNIT
#include <stddef.h>


/*
Функция сравнения для сортировок
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  
*/
int cmp(const void *pa, const void *pb);

int swap(void *p1, void *p2, size_t size);

/*
Сортировка пузырьком
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void sort_bubble(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *));


/*
Сортировка вставками базовая
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void sort_v(void *base, size_t nmemb, size_t size, 
            int(*compar)(const void *, const void *));


// Сортировка вставками с бинарным поиском
void sort_vbin(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *));



void sort_q(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *));

#endif // SORTUNIT
