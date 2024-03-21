#pragma warning(disable:4996)
#include "LinkList.h"
#include <stdio.h>

Status InitList_L(LinkList* L)//构造一个空的单链表L(默认带头结点)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!*L) 
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

Status GetElem_L(LinkList L, int i, ElemType* e)//查找第i个元素
{
	//L为带头节点的单链表的头指针
	//当第i个元素存在时，将值赋给e并返回OK，否则返回ERROR
	LinkList p=0;
	p = (LNode*)malloc(sizeof(LNode));
	p = L->next;
	int j = 1;//初始化，p指向第一个节点，j为计数器
	while (p && j < i)
	{
		//顺时针向后查找，直到p指向第i个元素或p为空
		p = p->next;
		++j;
	}
	if (!p || j > i)//j>i的作用是检查异常输入（i<=0)
		return ERROR;//第i个元素不存在
	else
	{
		*e = p->data;
		return OK;
	}
}

Status LocateElem_L(LinkList L, ElemType e)
{
	LinkList p = L->next;
	int i = 1;
	while (p)
	{
		if (p->data == e)
			return i;
		else
		{
			p = p->next;
			i++;
		}
	}
	return 0;
}

Status ListInsert_L(LinkList *L, int i, ElemType e)
{
	//在带头结点的单链线性表L的第i个元素之前插入e
	LinkList p,s;
	p = *L;
	int j = 0;
	while (p && j < i - 1)//寻找第i-1个元素
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;//i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNode));//生成新节点
	s->data = e;
	s->next = p->next;//插入L中
	p->next = s;
	return OK;
}

Status ListTraverse_L(LinkList L)
{
	LinkList p = L->next;
	if (!p)
		printf("链表为空！");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status ListDelete_L(LinkList* L, int i, ElemType* e)
{
	//在带头节点的单链线性表L中，删除第i个元素，e返回其值
	LinkList p, q;
	p = *L;
	int j = 0;
	while (p->next && j < i - 1)//寻找第i个
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

void CreateList_L(LinkList *L, int n)
{
	//逆位序输入n个元素的值，建立带表头结点的单链表L
	LinkList p;
	int i;
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//先建立一个带头结点的单链表
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新结点
		scanf("%d",&p->data);
		p->next = (*L)->next;
		(*L)->next = p;//插入到表头
	}
}

void CreateList_L_tail(LinkList *L, int n)
{
	//顺序输入n个元素的值，建立带表头结点的单链表L
	LinkList p, r;
	int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//先建立一个带头结点的单链表
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		scanf("%d",&p->data);
		r->next = p;
		r = p;//插入到表尾
	}
	r->next = NULL;
}