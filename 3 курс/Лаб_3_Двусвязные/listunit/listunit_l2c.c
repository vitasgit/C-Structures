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
    p->pprev = (*ph)->pprev;
    p->pnext = (*ph);
    (*ph)->pprev->pnext = p;
    (*ph)->pprev = p;
    *ph = p;
    return p;
}

pnodeL2C addLastNodeL2C(pnodeL2C *ph, pnodeL2C p)
{
    p->pprev = (*ph)->pprev;  // кладем адрес на узел слева
    p->pnext = *ph;  // кладем адрес на голову
    (*ph)->pprev->pnext = p;  // кладем в предпослдений узел адрас на конец
    (*ph)->pprev = p;  // кладем в голове адрес на новый конец
    return p;
}

pnodeL2C insertAfterNodeL2C(pnodeL2C pn, pnodeL2C p)
{
    p->pprev = pn;  // кладем адрес узла слева
    p->pnext = pn->pnext; // кладем адрес узла справа
    pn->pnext->pprev = p; // кладем в узел справа адрес новый узел
    pn->pnext = p;  // кладем в узел слева адрес новый узел
    return p;
}

pnodeL2C insertBeforeNodeL2C(pnodeL2C pn, pnodeL2C p)
{
    p->pnext = pn;  // кладем адрес узла справа
    p->pprev = pn->pprev;  // кладем адрес узла слева
    pn->pprev->pnext = p;  // в левый узел кладем адрес на новый
    pn->pprev = p;  // в правй узел кладем адрес на новый
    return p;
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

