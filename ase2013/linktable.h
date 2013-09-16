#include<stdio.h>
#include<stdlib.h>

/* Record of every student */
typedef struct Student
{
    int id;
    int name;
    struct Student * next;
}tStudent;

int insert(int id,int name);
tStudent* search(int id);