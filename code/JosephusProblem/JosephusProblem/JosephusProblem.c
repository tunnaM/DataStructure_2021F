#include "JosephusProblem.h"
#include <stdio.h>

Status create_list(LinkList *Tail, int n)//创建不带头节点不带头指针，只有尾指针的循环单链表
{
	LinkList p;	//创建一个临时的中间指针变量p
	LinkList head = (LinkList)malloc(sizeof(LNode));//创建一个头结点，head为指向头结点的指针
	if (head == NULL)
		return 0;//判断申请内存空间是否成功
	head->next = NULL;
	head->data = n;//head->data用来存储该链表中的节点数
	(*Tail)= head;//尾节点先指向头结点，因为需要从尾部插入节点
	for (int i = 1; i <= n; i++) 
	{
		p = (LinkList)malloc(sizeof(LNode));//创建一个节点
		p->data = i;
		p->next = (*Tail)->next;//插入
		(*Tail)->next = p;//节点p
		(*Tail) = p;//并将尾指针向后移动
	}
	(*Tail)->next = head->next;//让tail->next和head->next同时指向第一个节点，这样就相当于把头结点从循环链表中剔除
}

void Josephus(LinkList Tail, int n, int m)
{
	LinkList p = Tail->next;
	LinkList pre = Tail;
	while (p->next != p)
	{
		for (int i = 0; i < m - 1; i++)
		{
			pre = p;
			p = p->next;
		}
		printf("出列的人是%d号\n", p->data);
		pre->next = p->next;
		if (p == Tail)
			Tail = pre->next;
		free(p);
		p = pre->next;
	}
	printf("优胜者是%d号", p->data);
}