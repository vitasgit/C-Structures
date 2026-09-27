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

// Сортировка вставками с бинарным поиском
// i - эл для которого ищем место для вставки
// char *el - элемент которому нужно найти место, он правее границы на 1. Указатель на i
// k - 
void sort_vbin(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	char *tmp = malloc(size);  // или лучше использовать void *tmp. какое преимущество дает char?
	// free !!!!!
	for (int i = 1; i < nmemb; i++) {    //  int или size_t для i
		int l = 0;
		int r = i-1;   // границы по отсортированной области, а не всему массиву
		//int k = i;

		char *pi = (char*)base + i*size;  // элемент которому нужно найти место, он правее границы на 1
		while (l <= r) {
			int mi = (l + r)/2;  // серединный индекс
			char *pmi = (char*)base + mi*size;

			if (compar(pmi, pi) > 0) {  // если pmi > pi, то сдвигаем правую границу, идем налево 
				r = mi-1;  // сдвигаю правую границу. так как я сделал в cmp строго больше, то нет смысла в r присваивать середину, он точно не подходит, поэтому сдвигаю границу ещё на 1 влево.
			}
			else {
				l = mi+1;
			}
			// if (cmp(pmi, pi) == -1) {
			// 	l = mi+1;
			// }
		}
		memcpy(tmp, pi, size);
		
		// dst, src, n
		// l+1 --> (char*)base + (l+1)*size   	правее на 1 от границы l
		// l --> (char*)base + l*size 			указатель на саму границу l
		// (i-l)*size   						кол-во байт, которые нужно передвинуть.
		memmove((char*)base + (l+1)*size, (char*)base + l*size, (i-l)*size );
		memcpy((char*)base + l*size, tmp, size);

	}
	free(tmp);
}


int main()
{
    int arr[N] = {3, 2, 1};
    outArr(arr, N);

    // Вставками базовая
    sort_vbin(arr, N, sizeof(arr[0]), cmp);
    outArr(arr, N);



    return 0;
}
