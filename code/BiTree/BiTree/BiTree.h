#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>
#include "Status.h"

typedef int TElemType;
typedef struct BiTNode//结点结构
{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree Root(BiTree T);//1.求二叉树的根
int Value(BiTree T, BiTree e);//2.求二叉树中某个结点的值
Status Search(BiTree T, BiTree e);//辅助value函数
BiTree Parent(BiTree T, BiTree e);//3.求二叉树某一结点的双亲
BiTree LeftChild(BiTree T, BiTree e);//4.求二叉树某一结点的左孩子
BiTree RightChild(BiTree T, BiTree e);//5.求二叉树某一结点的右孩子
BiTree LeftSibling(BiTree T, BiTree e);//6.求二叉树某一结点的左兄弟
BiTree RightSibling(BiTree T, BiTree e);//7.求二叉树某一结点的右兄弟
Status BiTreeEmpty(BiTree T);//8.判空
int BiTreeDepth(BiTree T);//9.求深度
Status Visit(TElemType e);//辅助函数
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));//10.先序遍历
Status PreOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType));//11.中序遍历
Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType));
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));//12.后序遍历
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType));//13.层序遍历
Status InitBiTree(BiTree* T);//14.构造空二叉树
Status Assign(BiTree T, BiTree* e, TElemType value);//15.为二叉树中某个结点赋值
Status CreateBiTree(BiTree* T);//16.用先序遍历创建二叉树
Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);//17.插入
Status ClearBiTree(BiTree* T);//18.清空二叉树
Status DestroyBiTree(BiTree* T);//19.销毁二叉树
Status DeleteChild(BiTree T, BiTree p, int LR);//20.删除
void CountLeaf(BiTree T, int* count);//21.计算二叉树叶子结点的个数


#endif