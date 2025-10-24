#include "listunit_l1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pnodeL1 createNodeL1(char *data)
{
    tnodeL1 *p = malloc(sizeof(tnodeL1));
    //pnodeL1 p = malloc(sizeof(tnodeL1));
    p->data = malloc(strlen(data)+1);
    strcpy(p->data, data);
    //printf("data = %s\n", p->data);
    p->pnext = NULL;
    
    return p;
}

pnodeL1 addFirstNodeL1(pnodeL1 *ph, pnodeL1 p)
{
    p->pnext = *ph;
    *ph = p;
    return p;
}

pnodeL1 addLastNodeL1(pnodeL1 *ph, pnodeL1 p)
{
    if (*ph == NULL) {return addFirstNodeL1(ph, p);}
    pnodeL1 pt = *ph;

    while (pt->pnext != NULL) {pt = pt->pnext;}
    pt->pnext = p;
    
    return p;
}

pnodeL1 insertAfterNodeL1(pnodeL1 pn, pnodeL1 p)
{
    if (p == NULL) {
        return pn;
    }
    
    if (pn == NULL) {
        return p;
    }

    p->pnext = pn->pnext;
    pn->pnext = p;

    return p;
}

void disposeNodeL1(pnodeL1 *pn)
{
    if (pn == NULL || *pn == NULL) return;
    
    // printf("%s\n", (*pn)->data);
    // printf("%p\n", (*pn)->pnext);
    
    free((*pn)->data);
    free(*pn);
    *pn = NULL;
}

pnodeL1 deleteAfterNodeL1(pnodeL1 pn)
{
    if (pn == NULL || pn->pnext == NULL) {return NULL;}

    pnodeL1 pdn = pn->pnext;
    pn->pnext = pn->pnext->pnext;
    pdn->pnext = NULL;
    return pdn;
}

void disposeAfterNodeL1(pnodeL1 pn)
{
    if (pn == NULL || pn->pnext == NULL) {return;}

    pnodeL1 pdn = pn->pnext;
    pn->pnext = pn->pnext->pnext;
    //pdn->pnext = NULL;
    disposeNodeL1(&pdn);
}

void disposeListL1(pnodeL1 *ph)
{
    // printf("%s\n", (*ph)->data);
    // printf("%p\n", *ph);
    
    pnodeL1 ptmp;
    while (*ph != NULL) {
        ptmp = *ph;
        *ph = (*ph)->pnext;
        disposeNodeL1(&ptmp);
    }
}

void listActionL1(pnodeL1 ph, listfunc func)
{
    while (ph != NULL) {
        if (func(ph->data) == 0) {return;}

        ph = ph->pnext;
    }
}

void listOutL1(pnodeL1 ph)
{
    //tnodeL1 *p;
    pnodeL1 p;
    for (p = ph; p != NULL; p = p->pnext)  // (*p).next
    {
        printf("%s ", p->data);
    }
    printf("\n");
}

int listCountL1(pnodeL1 ph)
{
    int count = 0;
    tnodeL1 *p;
    for (p = ph; p != NULL; p = p->pnext)
    {
        count++;
    }
    
    return count;
}

char *listSumStr(char *dest, int maxsize, pnodeL1 ph, char *delimiter)
{
    //strcat(a, "world");
    
    if (maxsize==0 || dest==NULL) {
        return NULL;
    }

    dest[0] = '\0';
    int di = 0;  // индекс dest
    pnodeL1 p;
    for (p = ph; p != NULL; p = p->pnext)
    {
        int i = 0;
        while ((p->data[i] != '\0') && (di+1 < maxsize))
        {
            dest[di] =  p->data[i];
            i++;
            di++;
        }
        
        
        // if (strlen(dest) + strlen(p->data)+1 > maxsize) {
        //     break;
        // }

        // strcat(dest, p->data);

        if (p->pnext !=  NULL) {
            // printf("len = %d\n", strlen(delimiter));
            // printf("size = %d\n", maxsize);
            // if (strlen(dest) + strlen(delimiter)+1 > maxsize) {break;}
            // strcat(dest, delimiter);

            int j = 0;
            while ((delimiter[j] != '\0') && (di+1 < maxsize))
            {
                dest[di] = delimiter[j];
                j++;
                di++;
            }
        }
    }
    dest[di] = '\0';

    return dest;

}

int sumvar = 0;
int sum(char *ch) {
    sumvar += atoi(ch);
    return 1;
}
