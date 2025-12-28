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
    if (p == NULL) {return NULL;}

    if (*ph == NULL) {
        *ph = p;
        (*ph)->pnext = *(ph);
        (*ph)->pprev = *(ph);
        return p;
    }

    p->pprev = (*ph)->pprev;
    p->pnext = (*ph);
    (*ph)->pprev->pnext = p;
    (*ph)->pprev = p;
    *ph = p;
    return p;
}

pnodeL2C addLastNodeL2C(pnodeL2C *ph, pnodeL2C p)
{
    if (p == NULL) {return NULL;}
    
    if (*ph == NULL) {
        *ph = p;
        (*ph)->pnext = *(ph);
        (*ph)->pprev = *(ph);
        return p;
    }

    p->pprev = (*ph)->pprev;  // кладем адрес на узел слева
    p->pnext = *ph;  // кладем адрес на голову
    (*ph)->pprev->pnext = p;  // кладем в предпослдений узел адрас на конец
    (*ph)->pprev = p;  // кладем в голове адрес на новый конец
    return p;
}

pnodeL2C insertAfterNodeL2C(pnodeL2C pn, pnodeL2C p)
{
    if (pn == NULL || p == NULL) {return NULL;}

    p->pprev = pn;  // кладем адрес узла слева
    p->pnext = pn->pnext; // кладем адрес узла справа
    pn->pnext->pprev = p; // кладем в узел справа адрес новый узел
    pn->pnext = p;  // кладем в узел слева адрес новый узел
    return p;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!! почему если вставить узел перед головой, то он добавляется в конец, становится последним
pnodeL2C insertBeforeNodeL2C(pnodeL2C pn, pnodeL2C p)
{
    if (pn == NULL || p == NULL) {return NULL;}

    p->pnext = pn;  // кладем адрес узла справа
    p->pprev = pn->pprev;  // кладем адрес узла слева
    pn->pprev->pnext = p;  // в левый узел кладем адрес на новый
    pn->pprev = p;  // в правй узел кладем адрес на новый
    return p;
}

pnodeL2C deleteNodeL2C(pnodeL2C *ph, pnodeL2C pn)
{
    if (*ph == NULL || pn == NULL) {return NULL;}

    if ((*ph == pn) && (pn->pnext == *ph)) {  // когда всего один узел - голова
        pn->pnext = NULL;
        pn->pprev = NULL;
        *ph = NULL;
        return NULL;
    }

    if (pn = *ph) {  // когда pn = ph (удаляем голову)
        //(*ph)->pnext->pprev = (*ph)->pprev;
        *ph = (*ph)->pnext;
    }
    
    pn->pprev->pnext = pn->pnext;  // кладем в узел слева адрес на правый(pnext)
    pn->pnext->pprev = pn->pprev;  // кладем в узел справа адрес на левый(pprev)
    pn->pprev = NULL;
    pn->pnext = NULL;
    return pn;
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

