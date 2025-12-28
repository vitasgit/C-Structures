#include <stdio.h>
#include "listunit_l2c.h"

int main()
{
    pnodeL2C phead = NULL;
    phead = createNodeL2C(1.0);
    //printf("%.2f\n", phead->data);

    addFirstNodeL2C(&phead, createNodeL2C(2.0));
    addFirstNodeL2C(&phead, createNodeL2C(3.0));
    // printf("%.2f\n", phead->pprev->data);
    // printf("%.2f\n", phead->pprev->pprev->data);
    // printf("%.2f\n", phead->data);
    // listOutDbg(phead);
    listOutL2C(phead, 0);



    // tnodeL1 *p = phead;
    // printf("%s\n", p->data);  // выводит 1 (*p).data
    //phead = createNodeL1("1");  // присваивается указатель на узел, где есть значение "1"

    //tnodeL1 *phead = NULL;
    //pnodeL1 phead = NULL, n1, n2, n3, t;
    //phead = createNodeL1("1");
    // n1 = createNodeL1("2");
    // n2 = createNodeL1("3");
    // n3 = createNodeL1("4");
    // addFirstNodeL1(&phead, createNodeL1("46"));
    // addLastNodeL1(&phead, createNodeL1("53"));
    // addFirstNodeL1(&phead, createNodeL1("31"));
    // insertAfterNodeL1(phead->pnext, createNodeL1("4.5"));
    // t = deleteAfterNodeL1(phead->pnext);
    // disposeNodeL1(&t);
    // listOutL1(phead);
    // disposeListL1(&phead);
    
    // addLastNodeL1(&phead, n2);
    // addLastNodeL1(&phead, n3);
    //disposeListL1(&phead);
    //listOutL1(phead);
    // addLastNodeL1(&phead, createNodeL1("4"));
    // addLastNodeL1(&phead, createNodeL1("5"));
    // addLastNodeL1(&phead, createNodeL1("6"));
    // listOutL1(phead);
    // printf("----\n");
    //disposeListL1(&phead);

    //n1->pnext = n2;
    // printf("%p\n", n1);
    // disposeNodeL1(&n1);
    // printf("%p\n", n1);

    // n1 = addLastNodeL1(&phead, createNodeL1("2"));
    // n2 = addLastNodeL1(&phead, createNodeL1("3"));
    // n3 = addLastNodeL1(&phead, createNodeL1("4"));
    // listOutL1(phead);
    // printf("----\n");
    // deleteAfterNodeL1(n1);
    // //disposeAfterNodeL1(n1);
    // listOutL1(phead);


    // addLastNodeL1(&phead,n1);
    // addLastNodeL1(&phead,n2);
    // listOutL1(phead);
    // printf("----\n");
    // disposeListL1(&phead);
    // listOutL1(phead);

    
    // printf("----\n");
    // addFirstNodeL1(&phead, createNodeL1("7"));
    // listOutL1(phead);
    // printf("c = %d\n", listCountL1(phead));


    // delimeter должен вставляться столько, сколько влезет (строка формируется посимвольно)
    // char s[1];
    // char *d = "-+";
    // listOutL1(phead);
    // printf("str: %s\n", listSumStr(s, sizeof(s), phead, d));
    // disposeListL1(&phead);

    
    // listOutL1(phead);
    // listActionL1(phead, sum);
    // printf("sum = %d\n", sumvar);
    // disposeListL1(&phead);
    


    

    
    
    // listOutL1(phead);
    // insertAfterNodeL1(phead, createNodeL1("7"));
    // listOutL1(phead);
    // printf("%s\n", phead->data);

    // phead = createNodeL1("1");
    // listOutL1(phead);
    // insertAfterNodeL1(phead, createNodeL1("7"));
    // listOutL1(phead);







    // listOutL1(phead);
    // printf("----\n");
    // addFirstNodeL1(&phead, createNodeL1("2"));
    // listOutL1(phead);
    // printf("----\n");
    // addFirstNodeL1(&phead, createNodeL1("3"));
    // listOutL1(phead);

    // printf("----\n");
    // addLastNodeL1(&phead, createNodeL1("4"));
    // listOutL1(phead);

    // printf("----\n");
    // //printf("%s\n", phead->data);
    // insertAfterNodeL1(phead->pnext->pnext, createNodeL1("7"));
    // listOutL1(phead);



    // tnodeL1 a = {"1"}, b={"2"}, c={"3"}, t = {"10"};
    // phead = &a;
    // a.pnext = &b;
    // b.pnext = &c;
    // c.pnext = NULL;
    // printf("%s\n", a.data);  // выводит 1


    // tnodeL1 *p = phead;
    // printf("%s\n", p->data);  // выводит 1 (*p).data
    //phead = createNodeL1("1");  // присваивается указатель на узел, где есть значение "1"


    return 0;
}
