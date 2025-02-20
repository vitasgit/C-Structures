#include <stdio.h>

int count = 0;
int depth = 0;

void foo(int a, int b) {
    count++;
    if (depth < count) {
        depth = count;
    }
    
    if (a == 3 || b == 5) {
        count--;
        return;
    }

    foo(a+1, b);
    printf("конец foo(%d, %d)\n", a, b);
    foo(a, b+1);

    printf("конец foo(1, 5)\n");
    count--;
}


int main(int argc, char **argv)
{   
    foo(1, 3);

    printf("%d\n", depth);
    return 0;
}
