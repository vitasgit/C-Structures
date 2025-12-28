#include "listunit_l2c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pnodeL2C createNodeL2C(double data)
{
    pnodeL2C p = malloc(sizeof(tnodeL2C));
    p->data = data;
    p->pnext = p;
    p->pprev = p;
    return p;
}

pnodeL2C addFirstNodeL2C(pnodeL2C *ph, pnodeL2C p)
{
    // p->pnext = (*ph)->pprev;
    // p->pprev = (*ph)->pnext;
    // (*ph)->pnext = p->pprev;
    // (*ph)->pprev = p->pnext;
    // (*ph) = p;

    p->pprev = (*ph)->pprev;
    p->pnext = (*ph);
    (*ph)->pprev->pnext = p;
    (*ph)->pprev = p;
    *ph = p;
    
}

void listActionL2C(pnodeL2C ph, int fwd, listfunc func)
{
    pnodeL2C p = ph;
    if (fwd != 0) {
        do {
            if (func(p->data) == 0) return;
            p = p->pnext;
        } while (p != ph);
    }
    else {
        p = ph->pprev;
        do {
            if (func(p->data) == 0) return;
            p = p->pprev;
        } while (p != ph->pprev);  // чтобы выводил последний узел (голову)
    }
}

int nodeOutL2C(double data)
{
    printf("%.2f\n", data);
    return 1;
    // реализация "молотка"
}

void listOutL2C(pnodeL2C ph, int fwd)
{
    listActionL2C(ph, fwd, nodeOutL2C);
    // нельзя написать напрямую реализацию "молотка", так как сигнатура этого не позволяет.
}

void listOutDbg(pnodeL2C ph) {
    printf("--------\n");    
    pnodeL2C p = ph;
    do {
        printf("%.2f : pprev=%p %p pnext=%p\n", p->data, p->pprev, p, p->pnext);
        p = p->pnext;
    } while (p != ph);
}

