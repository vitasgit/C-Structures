#include <stdio.h>

int count = 0;
int depth = 0;

void foo(int a) {
    count++;
    if (depth < count) {
        depth = count;
    }
    
    if (a == 3) {
        count--;
        return;
    }

    foo(a+1);

    printf("конец foo(%d)\n", a);
    count--;
}


int main(int argc, char **argv)
{   
    foo(1);

    printf("%d\n", depth);
    return 0;
}
