#include <stdio.h>
#include "Stack.h"

void LineEdit();
void LineEdit()
{
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵�������
	char ch =0;
	char* temp=0;
	SqStack S;
	InitStack(&S);//�����ջS
	printf("������һ�У�#���ո�@�����У���\n");
	ch = getchar();
	while (ch != EOF)
	{
		//EOFȫ�Ľ�����WIN��Ctrl+Z;MAC:Ctrl+D
		printf("������Ϊ��\n");
		while (ch != EOF && ch != '\n')
		{
			switch (ch)
			{
			case '#':
				Pop(&S, &ch);
				break;//����ջ�ǿ�ʱ��ջ
			case '@':
				ClearStack(&S);
				break;//����SΪ��ջ
			default:
				Push(&S, ch);
				break;//��Ч�ַ���ջ��δ����ջ������
			}
			ch = getchar();//���ն˽�����һ���ַ�
		}
		temp = S.base;
		while (temp != S.top)
		{
			printf("%c", *temp);
			++temp;//����ջ�׵�ջ����ջ���ַ����������ù��̵�������
		}
		ClearStack(&S);//����SΪ��ջ
		printf("\n");
		if (ch != EOF)
		{
			printf("������һ�У�#���˸�@�����У���\n");
			ch = getchar();
		}
	}
	DestroyStack(&S);
}

int main()
{
	LineEdit();
	
	return 0;
}
