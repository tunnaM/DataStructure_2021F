#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include "Status.h"

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

Status InitList_L(LinkList* L);
Status GetElem_L(LinkList L, int i, ElemType* e);
Status LocateElem_L(LinkList L, ElemType e);
Status ListInsert_L(LinkList* L, int i, ElemType e);
Status ListTraverse_L(LinkList L);
Status ListDelete_L(LinkList* L, int i, ElemType* e);
void CreateList_L(LinkList *L, int n);
void CreateList_L_tail(LinkList* L, int n);

#endif