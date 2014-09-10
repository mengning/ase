
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.h                                                           */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/10                                                           */
/*  DESCRIPTION           :  linklist for menu program                                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/09/10
 *
 */


/* data struct and its operations */

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode * head, char * cmd);
/* show all cmd in listlist */
int ShowAllCmd(tDataNode * head);

