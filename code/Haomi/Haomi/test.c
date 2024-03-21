#include <stdio.h>

void move(char x, int n, char y)
{
	printf("%d��Բ�̣�%c-->%c\n", n, x, y);
}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, 1, z);//�����1��Բ�̴�x�Ƶ�z
	else
	{
		hanoi(n - 1, x, z, y);//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������
		move(x, n, z);//�����Ϊn��Բ�̴�x�Ƶ�z
		hanoi(n - 1, y, x, z);//��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x��������
	}
}

int main()
{
	int n;
	printf("�����뺺ŵ���Ĳ�����");
	scanf_s("%d", &n);
	printf("�ƶ��������£�\n");
	hanoi(n, 'x', 'y', 'z');

	return 0;
}