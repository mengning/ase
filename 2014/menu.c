
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/08/31
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    int     cmd;
    char    desc[DESC_LEN];
    struct  DataNode *next;
} tDataNode;

main()
{
    tDataNode *head = NULL;
    /* Init cmd list */
    int i;
    tDataNode * p = NULL;
    for (i=0; i<CMD_NUM; i++)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
        p->cmd = i;
        snprintf(p->desc, DESC_LEN, "This is %d cmd!", i);
        p->next = head;
        head = p;
    }
    printf("Menu List:\n");
    p = head;
    while(p != NULL)
    {
        printf("%d - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    /* cmd line begins */
    while(1)
    {
        int cmd;
        printf("Input a cmd number > ");
        scanf("%d", &cmd);
        if(cmd >= CMD_NUM)
        {
            printf("This is a wrong cmd number!\n ");
            continue;
        }
        p = head;
        while(p != NULL)
        {
            if(p->cmd == cmd)
            {
                printf("%d - %s\n", p->cmd, p->desc);
                break;
            }
            p = p->next;
        }
    }
}
