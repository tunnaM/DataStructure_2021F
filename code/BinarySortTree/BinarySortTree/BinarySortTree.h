#ifndef SEQUENTIALSEARCH_H
#define SEQUENTIALSEARCH_H

#include <stdlib.h>
#include "Status.h"

typedef int KeyType;
typedef char OtherInfoType;
typedef int TElemType;
typedef struct
{
	KeyType key;
	OtherInfoType info;
}ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void InitBiTree(BiTree* T);
Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree* p);
Status InsertBST(BiTree* T, ElemType e);
Status Visit(TElemType e);
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType));
Status DeleteBST(BiTree* T, KeyType key);
void Delete(BiTree* p);

#endif