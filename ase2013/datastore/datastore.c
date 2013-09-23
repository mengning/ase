
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  datastore.c                            */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :  datastore                              */
/*  MODULE NAME           :  datastore                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/09/23                             */
/*  DESCRIPTION           :  datastore implementation               */
/********************************************************************/

/*
 * Revision log:
 *
 * Create test stub,by Mengning,2012/09/23
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"datastore.h"

tLinkTable LinkTable;
tLinkTableNode * gNode = NULL;

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable()
{
	return &LinkTable;
}
/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
    }
	return SUCCESS;		
}
/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
    }
    gNode = pNode;
	return SUCCESS;		
}
/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
    }
    gNode = NULL;
	return SUCCESS;		
}

/*
 * Search a LinkTableNode from LinkTable
 * int Conditon(tLinkTableNode * pNode);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode))
{
    if(pLinkTable == NULL || Conditon == NULL)
	{
		return NULL;
    }
    if(Conditon(gNode) == SUCCESS)
    {
    	return gNode;				    
	}
	return NULL;
}

/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
	{
		return NULL;
    }    
	return gNode;
}

/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return NULL;
    }
	return gNode;
}

