#pragma warning(disable:4996)
#include "LinkList.h"
#include <stdio.h>

Status InitList_L(LinkList* L)//����һ���յĵ�����L(Ĭ�ϴ�ͷ���)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!*L) 
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

Status GetElem_L(LinkList L, int i, ElemType* e)//���ҵ�i��Ԫ��
{
	//LΪ��ͷ�ڵ�ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p=0;
	p = (LNode*)malloc(sizeof(LNode));
	p = L->next;
	int j = 1;//��ʼ����pָ���һ���ڵ㣬jΪ������
	while (p && j < i)
	{
		//˳ʱ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		++j;
	}
	if (!p || j > i)//j>i�������Ǽ���쳣���루i<=0)
		return ERROR;//��i��Ԫ�ز�����
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
	//�ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����e
	LinkList p,s;
	p = *L;
	int j = 0;
	while (p && j < i - 1)//Ѱ�ҵ�i-1��Ԫ��
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;//iС��1���ߴ��ڱ�
	s = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
	s->data = e;
	s->next = p->next;//����L��
	p->next = s;
	return OK;
}

Status ListTraverse_L(LinkList L)
{
	LinkList p = L->next;
	if (!p)
		printf("����Ϊ�գ�");
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
	//�ڴ�ͷ�ڵ�ĵ������Ա�L�У�ɾ����i��Ԫ�أ�e������ֵ
	LinkList p, q;
	p = *L;
	int j = 0;
	while (p->next && j < i - 1)//Ѱ�ҵ�i��
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
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList p;
	int i;
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½��
		scanf("%d",&p->data);
		p->next = (*L)->next;
		(*L)->next = p;//���뵽��ͷ
	}
}

void CreateList_L_tail(LinkList *L, int n)
{
	//˳������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList p, r;
	int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d",&p->data);
		r->next = p;
		r = p;//���뵽��β
	}
	r->next = NULL;
}