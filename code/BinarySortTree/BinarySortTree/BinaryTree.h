//
//  BinaryTree.h
//  BinaryTree
//
//  Created by WangGang on 2019/4/8.
//  Copyright © 2019 WangGang. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/* 二叉树的二叉链表存储表示--类型定义 */
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;                            //结点元素
	struct BiTNode* lchild, * rchild;           //左孩子指针  //右孩子指针
}BiTNode, * BiTree;                              //二叉树结点


/* 二叉树（二叉链表存储）函数列 表 */
void InitBiTree(BiTree* T);//构造空二叉树T (初始化二叉树)
Status CreateBiTree(BiTree* T);//Algorithm6.4：按先序序列构造二叉树
Status PreOrderTraverse(BiTree T, Status(Visit)(TElemType));//Algorithm 6.1：先序遍历二叉树
void InOrderTraverse(BiTree T, void(Visit)(TElemType));//中序遍历二叉树
void PostOrderTraverse(BiTree T, void(Visit)(TElemType));//后序遍历二叉树
Status LevelOrderTraverse(BiTree T, Status(Visit)(TElemType e)); //层序遍历二叉树

//----------------------------------------------//
Status InOrderTraverse_NonRecursive1(BiTree T, Status(Visit)(TElemType));//Algorithm 6.2：中序遍历(非递归)二叉树
Status InOrderTraverse_NonRecursive2(BiTree T, Status(Visit)(TElemType));//Algorithm 6.3：中序遍历(非递归)二叉树
int BiTreeDepth(BiTree T);//返回二叉树深度（层数）
void CountLeaf(BiTree T, int* count);

#endif /* BinaryTree_h */
