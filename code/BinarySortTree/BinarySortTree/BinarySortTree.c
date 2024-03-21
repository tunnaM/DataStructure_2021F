#define _CRT_SECURE_NO_WARNINGS
#include "BinarySortTree.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

void InitBiTree(BiTree* T)
{
	*T = NULL;
}

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree* p)
{
	if (!T)//���Ҳ��ɹ�
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data.key)//���ҳɹ�
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data.key)
		return SearchBST(T->lchild, key, T, &(*p));
	else
		return SearchBST(T->rchild, key, T, &(*p));
}

Status InsertBST(BiTree* T, ElemType e)
{
	BiTree p,s;
	if (!SearchBST(*T, e.key, NULL, &p))
	{
		s=(BiTree)malloc(sizeof(BiTNode));//�½ڵ�s
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;//����sΪ�µĸ��ڵ�
		else if (e.key < p->data.key)
			p->lchild = s;//����*sΪ*p������
		else
			p->rchild = s;//����*sΪ*p���Һ���
		return TRUE;
	}
	return FALSE;//�������н�㣬���ٲ���
}//InsertBST

Status Visit(TElemType e)
{
	printf("%d ", e);
	return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//���ö�������洢�ṹ���������������T�ĵݹ��㷨
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data.key))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}//InOrderTraverse

Status DeleteBST(BiTree* T, KeyType key)
{
	if (!(*T))
		return FALSE;//�����ڹؼ��ֵ���key������Ԫ��
	else
	{
		if (key == (*T)->data.key)
		{
			Delete(&(*T));
			return TRUE;
		}
		else if (key < (*T)->data.key)
			DeleteBST(&((*T)->lchild), key);
		else
			DeleteBST(&((*T)->rchild), key);
	}
}//DeleteBST

void Delete(BiTree* p)
{
	//�Ӷ�����������ɾ�����p�����ؽ�������������������
	BiTree q, s;
	if (!(*p)->rchild)
	{
		//������Ϊ������ֻ���ؽ�����������
		q = (*p);
		(*p) = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)
	{
		//������Ϊ����ֻ���ؽ�����������
		q = (*p);
		(*p) = (*p)->rchild;
		free(q);
	}
	else
	{
		//��������������
		q = (*p);
		s = (*p)->lchild;
		while (s->rchild)
		{
			//sָ��ɾ����ǰ��
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;//�ؽ�*q��������
		free(s);
	}
}//Delete