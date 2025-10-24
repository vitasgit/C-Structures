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



int main()
{
    // тест для push
    Data test[] = {10, 3, 17, 21};

    Node *list = NULL;
    printList(list);
    for(int i = sizeof(test)/sizeof(test[0]) - 1; i >= 0; i--) {
        push(&list, test[i]);
        printList(list);
    }
    
    return 0;
}