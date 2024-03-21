#include "JosephusProblem.h"
#include <stdio.h>

Status create_list(LinkList *Tail, int n)//��������ͷ�ڵ㲻��ͷָ�룬ֻ��βָ���ѭ��������
{
	LinkList p;	//����һ����ʱ���м�ָ�����p
	LinkList head = (LinkList)malloc(sizeof(LNode));//����һ��ͷ��㣬headΪָ��ͷ����ָ��
	if (head == NULL)
		return 0;//�ж������ڴ�ռ��Ƿ�ɹ�
	head->next = NULL;
	head->data = n;//head->data�����洢�������еĽڵ���
	(*Tail)= head;//β�ڵ���ָ��ͷ��㣬��Ϊ��Ҫ��β������ڵ�
	for (int i = 1; i <= n; i++) 
	{
		p = (LinkList)malloc(sizeof(LNode));//����һ���ڵ�
		p->data = i;
		p->next = (*Tail)->next;//����
		(*Tail)->next = p;//�ڵ�p
		(*Tail) = p;//����βָ������ƶ�
	}
	(*Tail)->next = head->next;//��tail->next��head->nextͬʱָ���һ���ڵ㣬�������൱�ڰ�ͷ����ѭ���������޳�
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
		printf("���е�����%d��\n", p->data);
		pre->next = p->next;
		if (p == Tail)
			Tail = pre->next;
		free(p);
		p = pre->next;
	}
	printf("��ʤ����%d��", p->data);
}