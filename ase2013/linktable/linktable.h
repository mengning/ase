
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  linktabe.h                             */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/12/30                             */
/*  DESCRIPTION           :  interface of Link Table                */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/12/30
 *
 */

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include <pthread.h>

/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
	struct LinkTableNode * pNext;
}tLinkTableNode;

/*
 * LinkTable Type
 */
typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int			SumOfNode;
	pthread_mutex_t mutex;
	
}tLinkTable;

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable();
/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable *pLinkTable);
/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);
/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);
/*
 * Search a LinkTableNode from LinkTable
 * tLinkTableNode * CmpFn(tLinkTable *pLinkTable);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * CmpFn(tLinkTable *pLinkTable));
/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);
/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);

#endif /* _LINK_TABLE_H_ */


