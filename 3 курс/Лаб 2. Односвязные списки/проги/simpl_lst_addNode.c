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
    Node *list = NULL;  // то же что struct Node *list = NULL
    Node a = {3}, b={17}, c={21}, t = {10};
    list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    // добавление первым способом
    // printList(list);
    // list = &t;
    // t.next = &a;
	// printList(list);

    // добавление через p
    // printList(list);
    // Node *p = &t;
    // p->next = &a;  // можно написать list, т.к. list хранит адрес на первый элемент (a)
    // list = p;
    // printList(list);

    printList(list);
    push(&list, 10);
    printList(list);
    
    return 0;
}