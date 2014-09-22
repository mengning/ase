#include<stdio.h>
#include"linktable.h"

#define debug

int results[3] = {1,1,1};
char * info[3] =
{
    {"test report"},
    {"TC1 CreateLinkTable"},
    {"TC2.1...."}
};

int main()
{
    int i;
    tLinkTable *p = CreateLinkTable();
    if(p == NULL)
    {
        debug("TC1 fail\n");
        results[1] = 1;
    }
    tLinkTableNode * pNode = NULL;   
    int ret = AddLinkTableNode(p,pNode);
    if(ret == FAILURE)
    {
        debug("TC2.1 Succ\n");
        results[2] = 0;       
    }
    /* more test case ...*/

    /* test report */
    printf("test report\n");
    for(i=1;i<=2;i++)
    {
        if(results[i] == 1)
        {
            printf("Testcase Number%d F - %s\n",i,info[i]);
        }
    }
}
