#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdio.h>
#include "String.h"

int main()
{
	int mm;
	mm = max(6, 20, 40, 10, 50, 30, 40);
	printf("���ֵΪ��%d\n", mm);

	system("pause");
	return 0;
}

int max(int n, ...)
{
	//����n��ʾ������������������
	va_list ap;//����һ��va_list ָ�������ʲ�����
	va_start(ap, n);//��ʼ��ap��ָ���һ�����
	int maximum = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		//��ȡһ��int�Ͳ���������apָ����һ������
		temp = va_arg(ap, int);
		if (maximum < temp)
			maximum = temp;
	}
	va_end(ap);//�����ر�ap
	return maximum;
}