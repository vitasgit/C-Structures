#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnodeL1 *pnodeL1;
typedef struct tnodeL1
{
    char *data;
    pnodeL1 pnext;
} tnodeL1;

pnodeL1 createNodeL1(char *data)
{
    tnodeL1 *p = malloc(sizeof(tnodeL1));
    p->data = malloc(strlen(data)+1);
    strcpy(p->data, data);
    p->pnext = NULL;
    
    return p;
}

void testFunction(pnodeL1 pn)
{
    printf("Внутри функции:\n");
    printf("Адрес pn: %p\n", (void*)&pn);
    printf("Значение pn: %p\n", (void*)pn);

    pn = createNodeL1("7");

    printf("После изменения pn:\n");
    printf("Адрес pn: %p\n", (void*)&pn);
    printf("Значение: %p\n", (void*)pn);
}

int main()
{
    pnodeL1 phead = NULL;  // указатель на структуру tnodeL1
    phead = createNodeL1("1");

    printf("В main() ДО вызова функции:\n");
    printf("Адрес phead: %p\n", (void*)&phead);  // адрес 
    printf("Значение phead: %p\n", (void*)phead);  // значение переменной (адрес на голову списка)

    printf("\nВызов testFunction(phead):\n");
    testFunction(phead);

    printf("\nВ main() ПОСЛЕ вызова функции:\n");
    printf("Адрес phead: %p\n", (void*)&phead);
    printf("Значение phead: %p\n", (void*)phead);
    printf("данные в узле: %s\n", phead->data);

    return 0;
}