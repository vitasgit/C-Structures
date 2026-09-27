#include "sortunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>   // !!!!!!!!!!!!!!!!
#include <string.h>  // memcpy


/*
Функция сравнения
Должна возвращать целое число меньше, больше нуля или равное ему, если первый аргумент, соответственно, меньше, больше второго или равен ему. Если два члена массива равны, то порядок их расположения в массиве не определен.  

*(const int *)pa  // сначала преобразовали указатель из типа void в тип const int, затем разыменовали и записали значение в переменную int a
*/
int cmp(const void *pa, const void *pb)
{
	int a = *(const int *)pa;  // Преобразование неопределенного указателя к указателю типа int*
    int b = *(const int *)pb;  // поменять для простоты на int b = *(int*)pb

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


!!!! иправить опечатку int --> void 
*/
int swap(void *p1, void *p2, size_t size)
{
	char *tmp = malloc(size);           // или лучше использовать void *tmp. какое преимущество дает char?
	memcpy(tmp, p1, size);
	memcpy(p1, p2, size);
	memcpy(p2, tmp, size);
	free(tmp);
}



/*
Сортировка пузырьком
Сортирует массив base, размера nmemb элементов, при этом каждый элемент имеет размер size

void *base - ссылка на начало массива
size_t nmemb - кол-во эл в переданном массиве
size_t size - размер одного элемента в переданном массиве
*/
void sort_bubble(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	char *p0 = (char *)base;  // получить указатель на начало массива, на первый байт
	char *tmp = malloc(size);  // указатель типа char на область памяти в size байтах (size ячеек по 1 байту(char))
	
	for (int i = 0; i < nmemb-1; i++) {  // перебираем каждый элемент(индекс)
		bool flag = 0;  // !!!!!!!!!!!!! заменить bool на int - лучше оставить, занимает 1 байт вместо 4. или заменить на char

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
		// !! можно сдвинуть правую границу влево, смысла переберать массив до последнего эдемента нет
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
void sort_v(void *base, size_t nmemb, size_t size, 
            int(*compar)(const void *, const void *))
{
	char *p0 = (char *)base;

	for (int i = 1; i < nmemb; i++) {
		int k = i;  // зачем нужна отдельная переменная, нельзя использовать просто i?
		//  !!! функция сравнения может возвращать разницу, у меня это не учтено: 5 - 2 = 3. у меня строго == 1, надо сделать: > 0
		while (k > 0 && cmp(p0 + (k-1)*size, (p0 + k*size)) == 1 ) {  // (p0 + (k-1)*size) > (p0 + k*size)
			swap(p0 + (k-1)*size, p0 + k*size, size);
			k -= 1;
		}
	}
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

			if (cmp(pmi, pi) > 0) {  // если pmi > pi, то сдвигаем правую границу, идем налево 
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

// Быстрая сортировка
void sort_q(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{
	int l = 0;  // начало индека
	int r = nmemb-1;  // последний индекс
	int c = (l+r)/2;
	if (l>r) {return;}  // базовый случай

	char *p0 = (char*)base;  // указатель на начало памяти
	char *pl = (char*)base;  // указатель на начало памяти
	char *pr = (char*)base + r*size;  // указатель на полследнию ячейку памяти
	char *pc = (char*)base + c*size;

	/* первый вариант через индексы (не высчитываю pl, pr)
	while (l <= r) {
		while (cmp(pl, pc) < 0) {l++; pl = (char*)base + l*size;}  // увеличиваем левую границу на 1 ячейку
		while (cmp(pr, pc) > 0) {r--;}  // увеличиваем правую границу на 1 ячейку
		if (l <= r) {
			swap(pl, pr, size);
			l++; r--;
		}
	}
	*/


	while (pl <= pr) {
		while (cmp(pl, pc) < 0) {pl += size;}  // увеличиваем левую границу на 1 ячейку
		while (cmp(pr, pc) > 0) {pr -= size;}  // увеличиваем правую границу на 1 ячейку
		if (pl <= pr) {
			swap(pl, pr, size);
			pl += size;
			pr -= size;
		}
	}

	sort_q((char*)base,l+1,size,cmp);
	sort_q((char*)base+r*size,nmemb-r,size,cmp);

}


void sort_q(void *base, size_t nmemb, size_t size, 
                int(*compar)(const void *, const void *))
{

	// if (nmemb < 2) return;  защита от переполнения пока не задумываемся
	// if () {return;}  // базовый случай

	char *pl = (char*)base;  // указатель на начало памяти
	char *pr = (char*)base + (nmemb-1)*size;  // указатель на полследнию ячейку памяти
	char *pc = (char*)base + (nmemb/2)*size;

	while (pl <= pr) {
		while (cmp(pl, pc) < 0) {pl += size;}  // увеличиваем левую границу на 1 ячейку
		while (cmp(pr, pc) > 0) {pr -= size;}  // увеличиваем правую границу на 1 ячейку
		if (pl <= pr) {
			swap(pl, pr, size);  // риск замены pc
			pl += size;
			pr -= size;
		}
	}

	// int k1 = (pl-(char*)base) / size;  // можно ли так?
	// int k2 = ((char*)base-pr) / size;
	int k1 = (pr - (char*)base)/size+1;  // зачем +1?
	int k2 = nmemb - (pl - (char*)base)/size;
	sort_q((char*)base, k1, size, cmp);
	sort_q(pl, k2, size, cmp);

}
