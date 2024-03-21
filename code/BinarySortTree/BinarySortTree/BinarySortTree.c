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
	if (!T)//查找不成功
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data.key)//查找成功
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
		s=(BiTree)malloc(sizeof(BiTNode));//新节点s
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;//插入s为新的根节点
		else if (e.key < p->data.key)
			p->lchild = s;//插入*s为*p的左孩子
		else
			p->rchild = s;//插入*s为*p的右孩子
		return TRUE;
	}
	return FALSE;//树中已有结点，不再插入
}//InsertBST

Status Visit(TElemType e)
{
	printf("%d ", e);
	return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//采用二叉链表存储结构，中序遍历二叉树T的递归算法
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
		return FALSE;//不存在关键字等于key的数据元素
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
	//从二叉排序树中删除结点p，并重接它的左子树或右子树
	BiTree q, s;
	if (!(*p)->rchild)
	{
		//右子树为空树则只需重接它的左子树
		q = (*p);
		(*p) = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)
	{
		//左子树为空树只需重接它的右子树
		q = (*p);
		(*p) = (*p)->rchild;
		free(q);
	}
	else
	{
		//左右子树都不空
		q = (*p);
		s = (*p)->lchild;
		while (s->rchild)
		{
			//s指向被删结点的前驱
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;//重接*q的左子树
		free(s);
	}
}//Delete