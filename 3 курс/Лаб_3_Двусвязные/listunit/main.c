#include <stdio.h>
#include "listunit_l2c.h"

int main()
{
    pnodeL2C phead, t, pbig = NULL;
    int count;
    double min, max;
    phead = createNodeL2C(1.0);
    // printf("%.2f\n", phead->data);

    addFirstNodeL2C(&phead, createNodeL2C(2.0));
    addFirstNodeL2C(&phead, createNodeL2C(-3.0));
    // printf("%.2f\n", phead->pprev->data);
    // printf("%.2f\n", phead->pprev->pprev->data);
    // printf("%.2f\n", phead->data);
    // listOutDbg(phead);
    listOutL2C(phead, 1);
    printf("\n");
    addLastNodeL2C(&phead, createNodeL2C(-4.0));
    listOutL2C(phead, 1);
    printf("\n");
    insertAfterNodeL2C(phead->pnext, createNodeL2C(2.5));
    listOutL2C(phead, 1);
    printf("\n");
    insertAfterNodeL2C(phead->pprev->pprev, createNodeL2C(1.5));
    listOutL2C(phead, 1);
    printf("\n");
    insertBeforeNodeL2C(phead, createNodeL2C(77.0));
    listOutL2C(phead, 1);

    // count = listCountL2C(phead);
    // count = listCountL2C(phead);
    // printf("count = %d\n", count);
    // disposeListL2C(&phead);
    //listOutDbg(phead);

    printf("minmax = %.2f\n", minmaxL2C(phead, 0));
    //disposeListL2C(&phead);

    printf("above = %.2f\n", abNodeL2C(phead, 1, 1, 2.0)->data);
    disposeListL2C(&phead);
    

    // printf("\n");
    // t = deleteNodeL2C(&phead, phead->pnext);
    // disposeNodeL2C(&t);
    // disposeListL2C(&phead);
    // listOutL2C(phead, 1);

    // когда один элемент
    // listOutL2C(phead, 1);
    // // t = deleteNodeL2C(&phead, phead);
    // // disposeNodeL2C(&t);
    // // listOutL2C(phead, 1);
    // disposeListL2C(&phead);


    return 0;
}
