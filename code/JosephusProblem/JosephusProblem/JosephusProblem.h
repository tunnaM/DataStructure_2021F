#ifndef JOSEPHUSPROBLEM_H
#define JOSEPHUSPROBLEM_H

#include <stdlib.h>
#include "Status.h"

typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

#endif