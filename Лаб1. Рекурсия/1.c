#include <stdio.h>

#define MAX 10
#define MIN 0

typedef char matrix_t[MAX][MAX+1];
matrix_t a = {
    "0110001100",
    "0100000010",
    "1111001111",
    "1101001100",
    "0001000100",
    "0000101111",
    "0000101000",
    "0000101000",
    "0001101100",
    "0010000100"
};

matrix_t a2 = {
    "0110001100",
    "0100000010",
    "1111001111",
    "1101001100",
    "0001000100",
    "0000101111",
    "0000101000",
    "0000101000",
    "0001101100",
    "0010000100"
};

matrix_t a3 = {
    "0110001100",
    "0100000010",
    "1111001111",
    "1101001100",
    "0001000100",
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


int count2 = 0;
int depth2 = 0;
void fill2(int x, int y)
{
    count2++;
    if (depth2 < count2) {
        depth2 = count2;
    }

    while (1) {
        if ((x < MIN) || (x >= MAX) || (y < MIN) || (y >= MAX) || (a2[y][x] != '0')) {
            count2--;
            break;
        }

        a2[y][x] = '*';
        fill2(x+1, y);
        fill2(x-1, y);
        fill2(x, y+1);
        y--;
    }

    //fill(x+1, y);
    //fill(x-1, y);
    //fill(x, y+1);
    // fill(x, y-1);


    //count--;
}

// заменить рекурсию по горизонтали на цикл(сокращение 2-х рекурсивных вызовов)
int count3 = 0;
int depth3 = 0;
int lx, rx;  // left x, right x
void fill3(int x, int y)
{
    count3++;
    if (depth3 < count3) {
        depth3 = count3;
    }

    while (1) {
        if ((x < MIN) || (x >= MAX) || (y < MIN) || (y >= MAX) || (a3[y][x] != '0')) {
            count3--;
            break;
        }

        for (int i = x; ; i++) {
            if ((i >= MAX) || (a3[y][i] == '1')) {
                rx = i-1;
                break;
            }
        }

        for (int i = x; ; i--) {
            if ((i < MIN) || (a3[y][i] == '1')) {
                lx = i+1;
                break;
            }
        }

        for (int i = lx; i <= rx; i++) {
            a3[y][i] = '*';
        }

        for (int i = lx; i <= rx; i++) {
            fill3(i, y+1);
            fill3(i, y-1);
        }
    }
}

void print(matrix_t s)
{
    for (int i = 0; i < MAX; i++) puts(s[i]);
}

int main(int argc, char **argv)
{
    print(a);
    printf("\n");

    fill(3, 9);  // col, row
    print(a);
    printf("depth = %d\n", depth);
    //printf("c = %d\n", count);
    printf("\n");

    fill2(3, 9);  // col, row
    print(a);
    printf("depth = %d\n", depth2);
    //printf("c = %d\n", count2);
    printf("\n");

    fill3(3, 9);  // col, row
    print(a);
    printf("depth = %d\n", depth3);
    //printf("c = %d\n", count3);

    // printf("\n");
    // fill2(0, 4);
    // print(a);
    // printf("depth = %d\n", depth);
    return 0;

}
