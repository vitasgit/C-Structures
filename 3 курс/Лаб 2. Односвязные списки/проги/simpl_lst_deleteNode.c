#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;  // тип struct Node
struct Node
{
    Data data;
    Node * next;
};


void printList(Node *list)
{
    Node *p;
    for (p = list; p != NULL; p = p->next)  //  p->next === (*p).next, в next лежит адрес следующего узла. p->next - перешли по указателю в поле next, разыменовали это поле, получили значение (адрес на следующий элемент), присвоили этот адрес в переменную p. То есть мы в переменную p записали адрес следующего узла. в поле next хранятся адреса.
    {
        printf("%d ", p->data);
    }
    printf("\n");
}


void push(Node **plist, Data d)
{
    //printf("sizeof(node) = %d", sizeof(Node));  // почему выводит 16?
    Node *p = malloc(sizeof(Node));  // сколько будет выделено памяти?
    p->data = d;
    p->next = *plist;  // *plist указывает на первый узел
    *plist = p;

}


int is_empty(Node *list)
{
    return list == NULL;
}

Data pop(Node ** plist) {
    Node * p = *plist;      // p указывает на верхний узел списка
    Data res = p->data;     // res - число, которое было на вершине списка
    *plist = p->next;       // list стал указывать на следующий узел
    free(p);                // удаленный узел - освободили память
    return res;             // вернули значение, которое было на вершине списка
}



int main()
{
    Data test[] = {10, 3, 17, 21};

    Node * list = NULL;
    printList(list);
    //printf("size=%d : \n", size(list));                     // size = 0
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: YES


    // тесты на push
    for(int i = sizeof(test)/sizeof(test[0]) - 1; i >= 0; i--) {
        push(&list, test[i]);
        printf("push(%d): ", test[i]);
        printList(list);
    }

    //printf("size=%d : \n", size(list));                     // size = 4
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: NO

    // тесты на pop
    while( ! is_empty(list)) {
        Data d = pop(&list);
        printf("pop(%d): ", d);
        printList(list);
    }

    //printf("size=%d : \n", size(list));                     // size = 0
    printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");   // Empty: YES

    return 0;
}