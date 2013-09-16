
#include"linktable.h"

tStudent * pHead = NULL;

int insert(int id,int name)
{
    tStudent * pStudent = NULL;
    pStudent        = (tStudent *)malloc(sizeof(tStudent));
    pStudent->id    = id;
    pStudent->name  = name;
    pStudent->next  = pHead;
    pHead           = pStudent;   
}
tStudent* search(int id)
{
    tStudent * pStudent = NULL;
    pStudent = pHead;
    while(pStudent->id != id)
    {
        pStudent = pStudent->next;
    }
    printf("find student %d\n",pStudent->id);   
}