#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LinkQueue.h"
#include "Stack.h"
#include "BiTree.h"
int main()
{
	BiTree T;
	//InitBiTree test
	if (InitBiTree(&T))
		printf("InitBiTree success!\n");
	else
		printf("InitBiTree unsuccess!\n");

	//CreateBiTree test
	char ch1, ch2, ch3;
	printf("请输入一个二叉树T:");
	if (CreateBiTree(&T))
		printf("CreateBiTree success!\n");
	else
		printf("CreateBiTree unsuccess!\n");
	ch1 = getchar();//吸收换行符

	//CountLeaf test
	int a = 0;
	CountLeaf(T, &a);
	printf("叶子节点个数为：%d\n", a);

	//BiTreeDepth test
	printf("S的深度为：%d\n", BiTreeDepth(T));


	/*
	//PreOrderTraverse test
	printf("先序遍历结果为：");
	PreOrderTraverse(T, Visit);
	printf("\n");

	//PreOrderTraverse1 test
	printf("先序遍历非递归结果为：");
	PreOrderTraverse(T, Visit);
	printf("\n");

	//ClearBiTree test
	if (ClearBiTree(&T))
		printf("ClearBiTree success!\n");
	else
		printf("ClearBiTree unsuccess!\n");
	printf("请输入新的二叉树T：");
	CreateBiTree(&T);
	ch2 = getchar();//吸收换行符

	//InOrderTraverse test
	printf("中序遍历结果为：");
	InOrderTraverse(T, Visit);
	printf("\n");

	//InOrderTraverse1 test
	printf("中序遍历非递归1结果为：");
	InOrderTraverse1(T, Visit);
	printf("\n");

	//InOrderTraverse1 test
	printf("中序遍历非递归2结果为：");
	InOrderTraverse2(T, Visit);
	printf("\n");

	//Root & Value test
	printf("根为：%c\n", Value(T, Root(T)));

	//BiTreeDepth test
	printf("S的深度为：%d\n", BiTreeDepth(T));

	//Parent test
	BiTree m = T->lchild->rchild;
	BiTree n = T->rchild;
	printf("D为：%c，F为：%c\n", Value(T, m), Value(T, n));
	printf("D的双亲为：%c，F的双亲为：%c\n", Value(T, Parent(T, m)), Value(T, Parent(T, n)));
	
	//Leftchild Rightchild Leftsibling Rightsibling test
	printf("D的左孩子为：%c，F的左孩子为：%c\n", Value(T, LeftChild(T, m)), Value(T, LeftChild(T, n)));
	printf("D的右孩子为：%c，F的右孩子为：%c\n", Value(T, RightChild(T, m)), Value(T, RightChild(T, n)));
	printf("D的左兄弟为：%c，F的左兄弟为：%c\n", Value(T, LeftSibling(T, m)), Value(T, LeftSibling(T, n)));
	printf("D的右兄弟为：%c，F的右兄弟为：%c\n", Value(T, RightSibling(T, m)), Value(T, RightSibling(T, n)));
	
	//Assign test
	printf("将F的值改为S\n");
	Assign(T, &n, 'S');

	//PostOrderTraverse test
	printf("后序遍历结果为：");
	PostOrderTraverse(T, Visit);
	printf("\n");

	//Insertchild test
	BiTree c;
	InitBiTree(&c);
	printf("请输入要插入结点的值:");
	CreateBiTree(&c);
	ch3= getchar();
	InsertChild(T, n, 0, c);//插到F左侧

	//LevelOrderTraverse test
	printf("插入F左孩子后层序遍历结果为：");
	LevelOrderTraverse(T, Visit);
	printf("\n");

	//DeleteChild test
	DeleteChild(T, m, 0);//删除m左侧
	printf("删除D左孩子后先序遍历T：");
	PreOrderTraverse(T,Visit);
	printf("\n");
	
	//Destroy test
	if (DestroyBiTree(&T))
		printf("DestroyBiTree success!\n");
	else
		printf("DestroyBiTree unsuccess!\n");

	system("pause");
	*/


	return 0;
}