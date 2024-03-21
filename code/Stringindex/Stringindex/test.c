#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stringindex.h"
#include <windows.h>
#include <time.h>

int main()
{
	int i, j, * p;
	SString S1, S2, T;
	StrAssign(S1, "acabaabaabcacaabc\0");
	printf("S1��Ϊ: ");
	StrPrint(S1);
	StrAssign(S2, "abaabcac\0");
	printf("S2��Ϊ: ");
	StrPrint(S2);

	int pos = 1;
	//Index test
	long op, ed;//���忪ʼʱ��ͽ���ʱ��
	op = clock();//��ʼ��ʱ
	for (int i = 0; i < 10000; i++)
	{
		Index(S1, S2, pos);
	}
	Sleep(1000);//��̬���������Ƶ�ǰ�������е��߳�
	ed = clock();//������ʱ
	printf("����ʱ��Ϊ%ldms\n", ed - op);//����ʱ�� 

	printf("�Ӵ�S2������S1�е�%d���ַ�֮���λ��\n", Index(S1, S2, pos));


	pos = 1;
	//Index_KMP test
	op = clock();//��ʼ��ʱ
	for (int i = 0; i < 10000; i++)
	{
		Index_KMP(S1, S2, pos);
	}
	Sleep(1000);//��̬���������Ƶ�ǰ�������е��߳�
	ed = clock();//������ʱ
	printf("KMP����ʱ��Ϊ%ldms\n", ed - op);//����ʱ�� 
	printf("�Ӵ�S2������S1�е�%d���ַ�֮���λ��\n", Index_KMP(S1, S2, pos));




	system("pause");
	return 0;
}

