#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // memcpy
#define N 3

/*
Функция сравнения
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  

*(const int *)pa  // сначала преобразовали указатель из типа void в тип const int, затем разыменовали и записали значение в переменную int a
*/
int cmp(const void *pa, const void *pb)
{
	int a = *(const int *)pa;  // Преобразование неопределенного указателя к указателю типа int*
    int b = *(const int *)pb; 

	if (a > b) return 1;
	else if (a < b) return -1;
	return 0;

	//return a-b;
}

/*
Функция  memcpy()  копирует n байт из участка памяти src в участок памяти dest. Адреса участков памяти не должны
       перекрываться друг другом. Если это неизбежно, используйте memmove(3).

ВОЗВРАЩАЕМОЕ ЗНАЧЕНИЕ
       Функция memcpy() возвращает указатель на dest.
*/
int swap(void *p1, void *p2, size_t size)
{
	char *tmp = malloc(size);
	memcpy(tmp, p1, size);
	memcpy(p1, p2, size);
	memcpy(p2, tmp, size);
	free(tmp);
}

// копирование побайтно
// void swap(void *a, void *b, size_t size) {
//         char tmp;
//         size_t i;
//         for (i = 0; i < size; i++) {
//                 tmp = *((char*)b + i);
//                 *((char*)b + i) = *((char*)a + i);
//                 *((char*)a + i) = tmp;
//         }
// }

void outArr(const int *parr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", parr[i]);
    }
    printf("\n");
}

void sort_q(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	if (nmemb < 2) return;  // базовый случай

	char *pl = (char*)base;  // указатель на начало памяти
	char *pr = (char*)base + (nmemb-1)*size;  // указатель на полследнию ячейку памяти
	char *pc = (char*)base + (nmemb/2)*size;
	char *tc = malloc(size);
	//*tc = *pc;  // баг, копирую только 1 байт (char)
	memcpy(tc, pc, size);  // защита от перезаписи

	while (pl <= pr) {
		while (cmp(pl, pc) < 0) {pl += size;}  // увеличиваем левую границу на 1 ячейку
		while (cmp(pr, pc) > 0) {pr -= size;}  // увеличиваем правую границу на 1 ячейку
		if (pl <= pr) {
			swap(pl, pr, size);  // риск замены pc
			pl += size;
			pr -= size;
		}
	}
	free(tc);

	int k1 = (pr - (char*)base)/size+1;
	int k2 = nmemb - (pl - (char*)base)/size;  // разобрать, упростить потом
	sort_q((char*)base, k1, size, cmp);  // левый
	sort_q(pl, k2, size, cmp);  // правый

}


int main()
{
    int arr[N] = {3, 2, 1};
    int arr2[9] = {8, 9, 7, 1, 2, 3, 4, 5, 6};
	outArr(arr2, 9);

    sort_q(arr2, 9, sizeof(arr2[0]), cmp);
    outArr(arr2, 9);



    return 0;
}
