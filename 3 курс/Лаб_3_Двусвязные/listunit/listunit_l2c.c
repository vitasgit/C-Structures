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
        return pn;
    }

    if (pn == *ph) {  // когда pn = ph (когда удаляем голову)
        //(*ph)->pnext->pprev = (*ph)->pprev;
        *ph = (*ph)->pnext;  // смещаем голову
    }
    
    pn->pprev->pnext = pn->pnext;  // кладем в узел слева адрес на правый(pnext)
    pn->pnext->pprev = pn->pprev;  // кладем в узел справа адрес на левый(pprev)
    pn->pprev = NULL;
    pn->pnext = NULL;
    return pn;
}

void disposeNodeL2C(pnodeL2C *pn)
{
    if (*pn == NULL) {return;}
    
    free(*pn);
    *pn = NULL;
}

void disposeListL2C(pnodeL2C *ph)
{
    if (*ph == NULL) {return;}

    // если список из одного элемента, то он указывает сам на себя и у себя pnext делает NULL
    (*ph)->pprev->pnext = NULL;
    pnodeL2C ptmp;
    while (*ph != NULL) {
        ptmp = *ph;
        *ph = (*ph)->pnext;
        disposeNodeL2C(&ptmp);
    }

    // pnodeL2C ptmp;
    // do {
    //     ptmp = *ph;
    //     *ph = (*ph)->pnext;
    //     disposeNodeL2C(&ptmp);
    // } while (ptmp != *ph);  // ptmp всегда NULL

    
    // pnodeL2C pstart = *ph;
    // pnodeL2C ptmp;
    
    // do {
    //     ptmp = *ph;
    //     *ph = (*ph)->pnext;
    //     free(ptmp);
    // } while (*ph != pstart);
    
    // *ph = NULL;

    // pnodeL2C ptmp;
    // do {
    //     ptmp = *ph;
    //     *ph = (*ph)->pnext;
    //     free(ptmp);
    // } while (*ph != (*ph)->pnext);
    
    // *ph = NULL;

}

pnodeL2C pcurrvar;
void listActionL2C(pnodeL2C ph, int fwd, listfunc func)
{
    if (ph == NULL) {return;}

    pnodeL2C p = ph;
    pcurrvar = NULL;
    if (fwd != 0) {
        do {
            pcurrvar = p;
            if (func(p->data) == 0) return;
            p = p->pnext;
        } while (p != ph);
    }
    else {
        p = ph->pprev;
        do {
            pcurrvar = p;
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

int countvar = 0;
int nodeCountL2C(double data){
    countvar++;
}

int listCountL2C(pnodeL2C ph)
{
    countvar = 0;
    int fwd = 1;
    listActionL2C(ph, fwd, nodeCountL2C);
    return countvar;
}

double minvar;
int nodeMinL2C(double data)
{
    if (minvar > data) {
        minvar = data;
    }

    return 1;  // возвращаю int значение чтобы продолжить перебор
}

double maxvar;
int nodeMaxL2C(double data)
{
    if (maxvar < data) {
        maxvar = data;
    }

    return 1;  // возвращаю int значение чтобы продолжить перебор
}

double minmaxL2C(pnodeL2C ph, int min)
{
    if (ph == NULL) {return 0;}

    minvar = ph->data;
    maxvar = ph->data;
    int fwd = 1;

    if (min!=0) {
        listActionL2C(ph, fwd, nodeMinL2C);
        return minvar;
    }
    else if (min==0) {
        listActionL2C(ph, fwd, nodeMaxL2C);
        return maxvar;
    }
    
    //return minvar;
}

//double bigvar;
int nodeBigL2C(double data)
{
    if (data > datavar) {
        //bigvar = data;
        return 0;
    }

    return 1;
}

int nodeSmallL2C(double data)
{
        if (data < datavar) {
        //bigvar = data;
        return 0;
    }

    return 1;
}

// возвращает первый (first!=0) или последний (first==0) элемент в списке, больший (above!=0)
// или меньший (above==0) data
double datavar;
pnodeL2C abNodeL2C(pnodeL2C ph, int first, int above, double data)
{
    if (ph == NULL) {return NULL;}
    int fwd;
    datavar = data;

    if (first!=0) {fwd = 1;}
    if (first==0) {fwd = 0;}

    if (above!=0) {listActionL2C(ph, fwd, nodeBigL2C);}
    if (above==0) {listActionL2C(ph, fwd, nodeSmallL2C);}

 
    return pcurrvar;
}

void listOutDbg(pnodeL2C ph) 
{
    printf("--------\n");    
    pnodeL2C p = ph;
    do {
        printf("%.2f : pprev=%p %p pnext=%p\n", p->data, p->pprev, p, p->pnext);
        p = p->pnext;
    } while (p != ph);
}

