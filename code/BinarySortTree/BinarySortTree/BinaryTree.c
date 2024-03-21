//
//  BinaryTree.c
//  BinaryTree
//
//  Created by WangGang on 2019/4/8.
//  Copyright ? 2019 WangGang. All rights reserved.
//

#include "BinaryTree.h"
#include "SequenceStack.h"    //栈
#include "CSqQueue.h"    //队列


void InitBiTree(BiTree* T)
{
	*T = NULL;
}

/* 算法6.4 */
/* 构造二叉链表表示的二叉树T */
Status CreateBiTree(BiTree* T)
{
	char ch;
	//    printf("请输入要创建的结点序列:\n");
	//    scanf("%c", &ch);
	ch = getchar();
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))
			return ERROR;
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return OK;
}


/* 算法6.1 */
/* 先序遍历二叉树T的递归算法 */
Status PreOrderTraverse(BiTree T, Status(Visit)(TElemType))
{
	if (T)
	{
		if (Visit(T->data))
		{
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		}
		return ERROR;
	}
	else
		return OK;
}

void InOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
}

void PostOrderTraverse(BiTree T, void(Visit)(TElemType))
{
	if (T)
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
	}
}

/*利用循环队列结构作为辅助，层序遍历二叉树*/
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType e)) //层序遍历二叉树
{
	if (T == NULL)
	{
		printf("当前树为空树，请先构造一颗非空二叉树！\n");
		return ERROR;
	}
	CSqQueue Q;
	BiTree p;
	InitQueue_CSq(&Q);
	EnQueue_CSq(&Q, T);
	while (!(QueueEmpty_CSq(Q)))
	{
		DeQueue_CSq(&Q, &p);
		if (!Visit(p->data))
			return ERROR;
		if (p->lchild != NULL)
			EnQueue_CSq(&Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue_CSq(&Q, p->rchild);
	}
	return OK;
}

//----------------------------------------------//

/* 算法6.2 */
/* 中序遍历二叉树T的非递归算法(1) */
Status InOrderTraverse_NonRecursive1(BiTree T, Status(Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	InitStack_Sq(&S);
	Push_Sq(&S, T);
	while (!StackEmpty_Sq(S))
	{
		while (GetTop_Sq(S, &p) && p)                //栈顶元素不为空
			Push_Sq(&S, p->lchild);                    //向左走到尽头
		Pop_Sq(&S, &p);                                //空指针退栈
		if (!StackEmpty_Sq(S))                        //访问结点，向右一步
		{
			Pop_Sq(&S, &p);
			if (!Visit(p->data))
				return ERROR;
			Push_Sq(&S, p->rchild);
		}
	}
	return OK;
}

/* 算法6.3 */
/* 中序遍历二叉树T的非递归算法(2) */
Status InOrderTraverse_NonRecursive2(BiTree T, Status(Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	InitStack_Sq(&S);
	p = T;
	while (p || !StackEmpty_Sq(S))
	{
		if (p)
		{
			Push_Sq(&S, p);
			p = p->lchild;
		}
		else
		{
			Pop_Sq(&S, &p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
}


void CountLeaf(BiTree T, int* count)
{
	if (T) {
		if ((!T->lchild) && (!T->rchild))
			(*count)++; // 对叶子结点计数
		CountLeaf(T->lchild, count);
		CountLeaf(T->rchild, count);
	} //if
} //CountLeaf

int BiTreeDepth(BiTree T)
{
	int depthLeft, depthRight, depthval;

	if (T == NULL)
		depthval = 0;                                //空树深度为0
	else
	{
		depthLeft = BiTreeDepth(T->lchild);            //求左子树深度
		depthRight = BiTreeDepth(T->rchild);            //求右子树深度

		depthval = (depthLeft >= depthRight ? depthLeft : depthRight) + 1;
	}
	return depthval;
}
