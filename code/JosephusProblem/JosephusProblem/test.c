#include "JosephusProblem.h"
#include <stdio.h>

int main()
{
	LinkList L;
	create_list(&L, 10);
	Josephus(L, 10, 3);

	return 0;
}