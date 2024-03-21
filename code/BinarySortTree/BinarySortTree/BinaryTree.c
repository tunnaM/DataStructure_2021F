//
//  BinaryTree.c
//  BinaryTree
//
//  Created by WangGang on 2019/4/8.
//  Copyright ? 2019 WangGang. All rights reserved.
//

#include "BinaryTree.h"
#include "SequenceStack.h"    //ջ
#include "CSqQueue.h"    //����


void InitBiTree(BiTree* T)
{
	*T = NULL;
}

/* �㷨6.4 */
/* ������������ʾ�Ķ�����T */
Status CreateBiTree(BiTree* T)
{
	char ch;
	//    printf("������Ҫ�����Ľ������:\n");
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


/* �㷨6.1 */
/* �������������T�ĵݹ��㷨 */
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

/*����ѭ�����нṹ��Ϊ�������������������*/
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType e)) //�������������
{
	if (T == NULL)
	{
		printf("��ǰ��Ϊ���������ȹ���һ�ŷǿն�������\n");
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

/* �㷨6.2 */
/* �������������T�ķǵݹ��㷨(1) */
Status InOrderTraverse_NonRecursive1(BiTree T, Status(Visit)(TElemType))
{
	SqStack S;
	BiTree p;
	InitStack_Sq(&S);
	Push_Sq(&S, T);
	while (!StackEmpty_Sq(S))
	{
		while (GetTop_Sq(S, &p) && p)                //ջ��Ԫ�ز�Ϊ��
			Push_Sq(&S, p->lchild);                    //�����ߵ���ͷ
		Pop_Sq(&S, &p);                                //��ָ����ջ
		if (!StackEmpty_Sq(S))                        //���ʽ�㣬����һ��
		{
			Pop_Sq(&S, &p);
			if (!Visit(p->data))
				return ERROR;
			Push_Sq(&S, p->rchild);
		}
	}
	return OK;
}

/* �㷨6.3 */
/* �������������T�ķǵݹ��㷨(2) */
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
			(*count)++; // ��Ҷ�ӽ�����
		CountLeaf(T->lchild, count);
		CountLeaf(T->rchild, count);
	} //if
} //CountLeaf

int BiTreeDepth(BiTree T)
{
	int depthLeft, depthRight, depthval;

	if (T == NULL)
		depthval = 0;                                //�������Ϊ0
	else
	{
		depthLeft = BiTreeDepth(T->lchild);            //�����������
		depthRight = BiTreeDepth(T->rchild);            //�����������

		depthval = (depthLeft >= depthRight ? depthLeft : depthRight) + 1;
	}
	return depthval;
}
