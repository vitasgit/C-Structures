/*
заменить хвостовую на рекурсию
заменить рекурсию по горизонатли на цикл
*/

#include <stdio.h>

#define MAX 10
#define MIN 0


typedef char matrix_t[MAX][MAX+1];

matrix_t a = {
    "0001001000",
    "0010010000",
    "0001010111",
    "0000001100",
    "0001100000",
    "0000101111",
    "0000101000",
    "0000101000",
    "0001101100",
    "0010000100"
};

int count = 0;
int depth = 0;
void fill(int x, int y)
{
    count++;
    if (depth < count) {
        depth = count;
    }

    if ((x < MIN) || (x >= MAX) || (y < MIN) || (y >= MAX) || (a[y][x] != '0')) {
        count--;
        return;
    }

    a[y][x] = '*';
    fill(x+1, y);
    fill(x-1, y);
    fill(x, y+1);
    fill(x, y-1);

    count--;
}

void print(matrix_t s)
{
    for (int i = 0; i < MAX; i++) puts(s[i]);
}

int main(int argc, char **argv)
{   
    print(a);
    printf("\n");

    fill(4, 0);
    print(a);
    printf("\ndepth = %d\n", depth);
	return 0;

}