#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdio.h>
#include "String.h"

int main()
{
	int mm;
	mm = max(6, 20, 40, 10, 50, 30, 40);
	printf("最大值为：%d\n", mm);

	system("pause");
	return 0;
}

int max(int n, ...)
{
	//定参n表示后面变参数量，定界用
	va_list ap;//定义一个va_list 指针来访问参数表
	va_start(ap, n);//初始化ap，指向第一个变参
	int maximum = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		//获取一个int型参数，并且ap指向下一个参数
		temp = va_arg(ap, int);
		if (maximum < temp)
			maximum = temp;
	}
	va_end(ap);//结束关闭ap
	return maximum;
}