
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  testlinktabe.c                         */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/12/30                             */
/*  DESCRIPTION           :  test of Link Table                     */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/12/30
 *
 */


#include"linktable.h"
#include<stdio.h>
#include<stdlib.h>

#define debug   

typedef struct Node
{
	tLinkTableNode * pNext;
	int data;
}tNode;

tLinkTableNode * Search(tLinkTable *pLinkTable);

int main()
{
    int i;
    tLinkTable * pLinkTable = CreateLinkTable();
    for(i = 0; i < 10; i++)
    {
        tNode* pNode = (tNode*)malloc(sizeof(tNode));
        pNode->data = i;
        debug("AddLinkTableNode\n");
        AddLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
    }
    debug("SearchLinkTableNode\n");
    tNode* pTempNode = (tNode*)SearchLinkTableNode(pLinkTable,Search);
    printf("%d\n",pTempNode->data);
    debug("DelLinkTableNode\n");
    DelLinkTableNode(pLinkTable,(tLinkTableNode *)pTempNode);
    free(pTempNode);
    DeleteLinkTable(pLinkTable);
}

tLinkTableNode * Search(tLinkTable *pLinkTable)
{
    debug("Search GetLinkTableHead\n");
    tNode * pNode = (tNode*)GetLinkTableHead(pLinkTable);
    while(pNode != NULL)
    {
        if(pNode->data == 5)
        {
            return  (tLinkTableNode*)pNode;  
        }
        debug("GetNextLinkTableNode\n");
        pNode = (tNode*)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
    }
    return NULL;
}