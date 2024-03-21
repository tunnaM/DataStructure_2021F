#include <stdio.h>

void move(char x, int n, char y)
{
	printf("%d号圆盘，%c-->%c\n", n, x, y);
}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);//将编号1的圆盘从x移到z
	else
	{
		hanoi(n - 1, x, z, y);//将x上编号为1至n-1的圆盘移到y，z作辅助塔
		move(x, n, z);//将编号为n的圆盘从x移到z
		hanoi(n - 1, y, x, z);//将y上编号为1至n-1的圆盘移到z，x作辅助塔
	}
}

int main()
{
	int n;
	printf("请输入汉诺塔的层数：");
	scanf_s("%d", &n);
	printf("移动步骤如下：\n");
	hanoi(n, 'x', 'y', 'z');

	return 0;
}