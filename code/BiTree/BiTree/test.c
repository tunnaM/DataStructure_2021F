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
	printf("������һ��������T:");
	if (CreateBiTree(&T))
		printf("CreateBiTree success!\n");
	else
		printf("CreateBiTree unsuccess!\n");
	ch1 = getchar();//���ջ��з�

	//CountLeaf test
	int a = 0;
	CountLeaf(T, &a);
	printf("Ҷ�ӽڵ����Ϊ��%d\n", a);

	//BiTreeDepth test
	printf("S�����Ϊ��%d\n", BiTreeDepth(T));


	/*
	//PreOrderTraverse test
	printf("����������Ϊ��");
	PreOrderTraverse(T, Visit);
	printf("\n");

	//PreOrderTraverse1 test
	printf("��������ǵݹ���Ϊ��");
	PreOrderTraverse(T, Visit);
	printf("\n");

	//ClearBiTree test
	if (ClearBiTree(&T))
		printf("ClearBiTree success!\n");
	else
		printf("ClearBiTree unsuccess!\n");
	printf("�������µĶ�����T��");
	CreateBiTree(&T);
	ch2 = getchar();//���ջ��з�

	//InOrderTraverse test
	printf("����������Ϊ��");
	InOrderTraverse(T, Visit);
	printf("\n");

	//InOrderTraverse1 test
	printf("��������ǵݹ�1���Ϊ��");
	InOrderTraverse1(T, Visit);
	printf("\n");

	//InOrderTraverse1 test
	printf("��������ǵݹ�2���Ϊ��");
	InOrderTraverse2(T, Visit);
	printf("\n");

	//Root & Value test
	printf("��Ϊ��%c\n", Value(T, Root(T)));

	//BiTreeDepth test
	printf("S�����Ϊ��%d\n", BiTreeDepth(T));

	//Parent test
	BiTree m = T->lchild->rchild;
	BiTree n = T->rchild;
	printf("DΪ��%c��FΪ��%c\n", Value(T, m), Value(T, n));
	printf("D��˫��Ϊ��%c��F��˫��Ϊ��%c\n", Value(T, Parent(T, m)), Value(T, Parent(T, n)));
	
	//Leftchild Rightchild Leftsibling Rightsibling test
	printf("D������Ϊ��%c��F������Ϊ��%c\n", Value(T, LeftChild(T, m)), Value(T, LeftChild(T, n)));
	printf("D���Һ���Ϊ��%c��F���Һ���Ϊ��%c\n", Value(T, RightChild(T, m)), Value(T, RightChild(T, n)));
	printf("D�����ֵ�Ϊ��%c��F�����ֵ�Ϊ��%c\n", Value(T, LeftSibling(T, m)), Value(T, LeftSibling(T, n)));
	printf("D�����ֵ�Ϊ��%c��F�����ֵ�Ϊ��%c\n", Value(T, RightSibling(T, m)), Value(T, RightSibling(T, n)));
	
	//Assign test
	printf("��F��ֵ��ΪS\n");
	Assign(T, &n, 'S');

	//PostOrderTraverse test
	printf("����������Ϊ��");
	PostOrderTraverse(T, Visit);
	printf("\n");

	//Insertchild test
	BiTree c;
	InitBiTree(&c);
	printf("������Ҫ�������ֵ:");
	CreateBiTree(&c);
	ch3= getchar();
	InsertChild(T, n, 0, c);//�嵽F���

	//LevelOrderTraverse test
	printf("����F���Ӻ����������Ϊ��");
	LevelOrderTraverse(T, Visit);
	printf("\n");

	//DeleteChild test
	DeleteChild(T, m, 0);//ɾ��m���
	printf("ɾ��D���Ӻ��������T��");
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