#include "BiTree.h"
#include "LinkQueue.h"
#include "LinkQueue.c"
#include "Stack.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

BiTree Root(BiTree T)
{
	//���ض������ĸ���ǰ��T����
	return T;
}

int Value(BiTree T, BiTree e)
{
	//��e��T��ĳ����㣬����e��ֵ��ǰ��T����
	if (Search(T, e) == TRUE)
		return e->data;
	else
		return '.';
}

Status Search(BiTree T, BiTree e)
{
	//��������
	if (!T)
		return FALSE;
	if (T == e || Search(T->lchild, e) == TRUE || Search(T->rchild, e) == TRUE)
		return TRUE;
	else
		return FALSE;
}

BiTree Parent(BiTree T, BiTree e)
{
	//��e��T��ĳ���Ǹ���㣬�򷵻�����˫�ף����򷵻�NULL��ǰ��T����
	if (T == e)
		return NULL;

	if (T->lchild == e || T->rchild == e)
		return T;
	else if (Search(T->lchild, e) == TRUE)
		return Parent(T->lchild, e);
	else if (Search(T->rchild, e) == TRUE)
		return Parent(T->rchild, e);
	else
		return NULL;
}

BiTree LeftChild(BiTree T, BiTree e)
{
	//��e��T��ĳ����㣬����e�����ӡ���e�����ӣ��򷵻�NULL��ǰ��T����
	if (Search(T, e) == TRUE)
		return e->lchild;
	else
		return NULL;
}

BiTree RightChild(BiTree T, BiTree e)
{
	//��e��T��ĳ����㣬����e���Һ��ӡ���e���Һ��ӣ��򷵻�NULL��ǰ��T����
	if (Search(T, e) == TRUE)
		return e->rchild;
	else
		return NULL;
}

BiTree LeftSibling(BiTree T, BiTree e)
{
	//e��T��ĳ����㣬����e�����ֵܡ���e����˫�׵����ӻ������ֵܣ��򷵻�NULL��ǰ��T����
	if (Search(T, e) == TRUE && Parent(T, e)->lchild != e)
		return Parent(T, e)->lchild;
	else
		return NULL;
}
 
BiTree RightSibling(BiTree T, BiTree e)
{
	//e��T��ĳ����㣬����e�����ֵܡ���e����˫�׵��Һ��ӻ������ֵܣ��򷵻�NULL��ǰ��T����
	if (Search(T, e) == TRUE && Parent(T, e)->rchild != e)
		return Parent(T, e)->rchild;
	else
		return NULL;
}

Status BiTreeEmpty(BiTree T)
{ 
	//��TΪ�ն�����,�򷵻�TRUE,����FALSE
	if (T)
		return FALSE;
	else
		return TRUE;
}

int BiTreeDepth(BiTree T)
{
	int lchildHeight, rchildHeight;
	if (T == NULL)
		return 0;
	lchildHeight = BiTreeDepth(T->lchild);
	rchildHeight = BiTreeDepth(T->rchild);
	return (lchildHeight > rchildHeight) ? (1 + lchildHeight) : (1 + rchildHeight);
}

Status Visit(TElemType e)
{
	printf("%c", e);
	return OK;
}

Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ĵݹ��㷨
	if (T)
	{
		if (Visit(T->data))//���ʽ��
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

Status PreOrderTraverse1(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ķǵݹ��㷨
	SqStack S;
	BiTree p;
	InitStack(&S);
	p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			if (!Visit(p->data))
				return ERROR;
			Push(&S, p->rchild);//�Һ�����ջ
			p = p->lchild;
		}
		else//������һ�㣬��������δ�����ʵĽ��
		{
			Pop(&S, &p);
		}
	}
	return OK;
}//PreOrderTraverse

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ĵݹ��㷨
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}//InOrderTraverse

Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ķǵݹ��㷨��1��
	SqStack S;
	BiTree p;
	InitStack(&S);
	Push(&S, T);//��ָ���ջ
	while (!StackEmpty(S))
	{
		while (GetTop(S, &p) && p)
			Push(&S, p->lchild);//�����ߵ���ͷ
		Pop(&S, &p);//��ָ����ջ
		if (!StackEmpty(S))//���ʽ�㣬����һ��
		{
			Pop(&S, &p);
			if (!Visit(p->data))
				return ERROR;
			Push(&S, p->rchild);
		}
	}
	return OK;
}

Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ķǵݹ��㷨��2��
	SqStack S;
	BiTree p;
	InitStack(&S);
	p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(&S, p);//�ǿ�ָ���ջ���������
			p = p->lchild;
		}
		else//�ϲ�ָ����ջ����������ָ��㣬�����ҽ�
		{
			Pop(&S,&p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return ERROR;
}//InOrderTraverse

Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ����������������T�ĵݹ��㷨
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}//PostOrderTraverse

Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType))
{
	if (T == NULL)
		return ERROR;
	LinkQueue Q;
	BiTree p;
	InitQueue(&Q);
	EnQueue(&Q, T);
	while (!(QueueEmpty(Q)))
	{
		DeQueue(&Q, &p);
		if (!Visit(p->data))
			return ERROR;
		if (p->lchild != NULL)
			EnQueue(&Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(&Q, p->rchild);
	}
	return OK;
}

Status InitBiTree(BiTree* T)
{
	//����ն�����
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	if (!(*T)) 
		exit(OVERFLOW);
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return OK;
}

Status Assign(BiTree T, BiTree* e, TElemType value)
{
	//��e��T��ĳ����㣬���e��ֵΪvalue��ǰ��T����
	if (Search(T, *e) == TRUE)
	{
		(*e)->data = value;
		return OK;
	}
	return ERROR;
}

Status CreateBiTree(BiTree *T)
{
	//�������������������
	//example1:AB#C##D## example2:ABC##DE#G##F###
	char ch;
	ch = getchar();
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!(*T))
			return ERROR;
		(*T)->data = ch;//���ɽ��
		CreateBiTree(&((*T)->lchild));//����������
		CreateBiTree(&((*T)->rchild));//����������
	}
	return OK;
}//CreateBiTree

Status InsertChild(BiTree T, BiTree p, int LR, BiTree c)
{
	//T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ�ա�
	//����LRΪ0��1������cΪT��p��ָ���������������p��ָ����ԭ��������������Ϊc����������
	if (!T || Search(T, p) == FALSE)
		return ERROR;
	BiTree q;
	if (LR == 0)
	{
		q = p->lchild;
		p->lchild = c;
		c->rchild = q;
	}
	else if (LR == 1)
	{
		q = p->rchild;
		p->rchild = c;
		c->rchild = q;
	}
	else
		return ERROR;
	return OK;
}

Status ClearBiTree(BiTree* T)
{
	if (!(*T))
	{
		return FALSE;
	}
	ClearBiTree(&((*T)->lchild));
	ClearBiTree(&((*T)->rchild));
	free(*T);
	*T = NULL;
	return TRUE;
}

Status DestroyBiTree(BiTree* T)
{
	//���ٶ�������ǰ��T����
	if (!(*T))
		return OK;
	DestroyBiTree(&((*T)->lchild));
	DestroyBiTree(&((*T)->rchild));
	free(*T);
	return OK;
}

Status DeleteChild(BiTree T, BiTree p, int LR)
{
	//T���ڣ�pָ��T��ĳ����㣬LRΪ0��1������LRΪ0��1��ɾ��T��p��ָ�������������
	if (T && Search(T, p) == FALSE)
		return ERROR;
	if (LR == 0)
	{
		DestroyBiTree(&p->lchild);
		p->lchild = NULL;
	}
	else if (LR == 1)
	{
		DestroyBiTree(&p->rchild);
		p->rchild = NULL;
	}
	else
		return ERROR;
	return OK;
}

void CountLeaf(BiTree T, int* count)
{
	if (T)
	{
		if ((!T->lchild) && (!T->rchild))
			(*count)++;//��Ҷ�ӽ�����
		CountLeaf(T->lchild, &(*count));
		CountLeaf(T->rchild, &(*count));
	}//if
}//CountLeaf