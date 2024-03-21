#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>
#include "Status.h"

typedef int TElemType;
typedef struct BiTNode//���ṹ
{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree Root(BiTree T);//1.��������ĸ�
int Value(BiTree T, BiTree e);//2.���������ĳ������ֵ
Status Search(BiTree T, BiTree e);//����value����
BiTree Parent(BiTree T, BiTree e);//3.�������ĳһ����˫��
BiTree LeftChild(BiTree T, BiTree e);//4.�������ĳһ��������
BiTree RightChild(BiTree T, BiTree e);//5.�������ĳһ�����Һ���
BiTree LeftSibling(BiTree T, BiTree e);//6.�������ĳһ�������ֵ�
BiTree RightSibling(BiTree T, BiTree e);//7.�������ĳһ�������ֵ�
Status BiTreeEmpty(BiTree T);//8.�п�
int BiTreeDepth(BiTree T);//9.�����
Status Visit(TElemType e);//��������
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));//10.�������
Status PreOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType));//11.�������
Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType));
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));//12.�������
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType));//13.�������
Status InitBiTree(BiTree* T);//14.����ն�����
Status Assign(BiTree T, BiTree* e, TElemType value);//15.Ϊ��������ĳ����㸳ֵ
Status CreateBiTree(BiTree* T);//16.�������������������
Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);//17.����
Status ClearBiTree(BiTree* T);//18.��ն�����
Status DestroyBiTree(BiTree* T);//19.���ٶ�����
Status DeleteChild(BiTree T, BiTree p, int LR);//20.ɾ��
void CountLeaf(BiTree T, int* count);//21.���������Ҷ�ӽ��ĸ���


#endif