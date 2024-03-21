#include "BiTree.h"
#include "LinkQueue.h"
#include "LinkQueue.c"
#include "Stack.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

BiTree Root(BiTree T)
{
	//返回二叉树的根，前提T存在
	return T;
}

int Value(BiTree T, BiTree e)
{
	//若e是T中某个结点，返回e的值，前提T存在
	if (Search(T, e) == TRUE)
		return e->data;
	else
		return '.';
}

Status Search(BiTree T, BiTree e)
{
	//辅助函数
	if (!T)
		return FALSE;
	if (T == e || Search(T->lchild, e) == TRUE || Search(T->rchild, e) == TRUE)
		return TRUE;
	else
		return FALSE;
}

BiTree Parent(BiTree T, BiTree e)
{
	//若e是T中某个非根结点，则返回它的双亲，否则返回NULL，前提T存在
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
	//若e是T中某个结点，返回e的左孩子。若e无左孩子，则返回NULL，前提T存在
	if (Search(T, e) == TRUE)
		return e->lchild;
	else
		return NULL;
}

BiTree RightChild(BiTree T, BiTree e)
{
	//若e是T中某个结点，返回e的右孩子。若e无右孩子，则返回NULL，前提T存在
	if (Search(T, e) == TRUE)
		return e->rchild;
	else
		return NULL;
}

BiTree LeftSibling(BiTree T, BiTree e)
{
	//e是T中某个结点，返回e的左兄弟。若e是其双亲的左孩子或无左兄弟，则返回NULL，前提T存在
	if (Search(T, e) == TRUE && Parent(T, e)->lchild != e)
		return Parent(T, e)->lchild;
	else
		return NULL;
}
 
BiTree RightSibling(BiTree T, BiTree e)
{
	//e是T中某个结点，返回e的右兄弟。若e是其双亲的右孩子或无右兄弟，则返回NULL，前提T存在
	if (Search(T, e) == TRUE && Parent(T, e)->rchild != e)
		return Parent(T, e)->rchild;
	else
		return NULL;
}

Status BiTreeEmpty(BiTree T)
{ 
	//若T为空二叉树,则返回TRUE,否则FALSE
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
	//采用二叉链表存储结构，先序遍历二叉树T的递归算法
	if (T)
	{
		if (Visit(T->data))//访问结点
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
	//采用二叉链表存储结构，先序遍历二叉树T的非递归算法
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
			Push(&S, p->rchild);//右孩子入栈
			p = p->lchild;
		}
		else//返回上一层，继续遍历未曾访问的结点
		{
			Pop(&S, &p);
		}
	}
	return OK;
}//PreOrderTraverse

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{
	//采用二叉链表存储结构，中序遍历二叉树T的递归算法
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
	//采用二叉链表存储结构，中序遍历二叉树T的非递归算法（1）
	SqStack S;
	BiTree p;
	InitStack(&S);
	Push(&S, T);//根指针进栈
	while (!StackEmpty(S))
	{
		while (GetTop(S, &p) && p)
			Push(&S, p->lchild);//向左走到尽头
		Pop(&S, &p);//空指针退栈
		if (!StackEmpty(S))//访问结点，向右一步
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
	//采用二叉链表存储结构，中序遍历二叉树T的非递归算法（2）
	SqStack S;
	BiTree p;
	InitStack(&S);
	p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(&S, p);//非空指针进栈，继续左进
			p = p->lchild;
		}
		else//上层指针退栈，访问其所指结点，再向右进
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
	//采用二叉链表存储结构，后续遍历二叉树T的递归算法
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
	//构造空二叉树
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	if (!(*T)) 
		exit(OVERFLOW);
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return OK;
}

Status Assign(BiTree T, BiTree* e, TElemType value)
{
	//若e是T中某个结点，结点e赋值为value，前提T存在
	if (Search(T, *e) == TRUE)
	{
		(*e)->data = value;
		return OK;
	}
	return ERROR;
}

Status CreateBiTree(BiTree *T)
{
	//用先序遍历创建二叉树
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
		(*T)->data = ch;//生成结点
		CreateBiTree(&((*T)->lchild));//构造左子树
		CreateBiTree(&((*T)->rchild));//构造右子树
	}
	return OK;
}//CreateBiTree

Status InsertChild(BiTree T, BiTree p, int LR, BiTree c)
{
	//T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空。
	//根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树。
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
	//销毁二叉树，前提T存在
	if (!(*T))
		return OK;
	DestroyBiTree(&((*T)->lchild));
	DestroyBiTree(&((*T)->rchild));
	free(*T);
	return OK;
}

Status DeleteChild(BiTree T, BiTree p, int LR)
{
	//T存在，p指向T中某个结点，LR为0或1。根据LR为0或1，删除T中p所指结点的左或右子树
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
			(*count)++;//对叶子结点计数
		CountLeaf(T->lchild, &(*count));
		CountLeaf(T->rchild, &(*count));
	}//if
}//CountLeaf