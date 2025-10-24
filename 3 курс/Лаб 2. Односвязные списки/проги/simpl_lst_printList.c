#include <stdio.h>

typedef int Data;

typedef struct Node Node;  // тип struct Node
struct Node
{
    Data data;
    Node *next;
};


void printList(Node *list)
{
    Node *p;
    for (p = list; p != NULL; p = p->next)  //  p->next === (*p).next, в next лежит адрес следующего узла. p->next - перешли по указателю в поле next, разыменовали это поле, получили значение (адрес на следующий элемент), присвоили этот адрес в переменную p. То есть мы в переменную p записали адрес следующего узла. в поле next хранятся адреса.
    {
        printf("%d ", p->data);
        printf("\n");
    }
}



int main()
{
    Node *list = NULL;  // то же что struct Node *list = NULL
    Node a = {3}, b={17}, c={21}, t = {10};
    list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    Node *p = list;  // p указывает на адрес a

    /* вывод значений узлов вручную
    /*
    Операция стрелка (->) - это оператор доступа к полю структуры через указатель. Она объединяет в себе две операции: Разыменование указателя и доступ к полю структуры. Эквивалент команды (*p).data.
    */

    /*
    printf("%d ", a.data);  // выведет значение, через доступ к полю (оператор .)
    printf("%d ", p->data);  // выведет значение, которое лежит в узле a, через указатель (оператор ->)
    p = p->next;
    printf("%d ", p->data);
    p = p->next;
    printf("%d ", p->data);
    printf("\n");
    */
	printList(p);
    
    return 0;
}