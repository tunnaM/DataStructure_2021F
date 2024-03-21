#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "HashSearch.h"


int main()
{
    ElemType r[N] = { 17,60,29,38,1,2,3,4,60,13 };
    HashTable H;
    int i, j, p;
    KeyType K;
    InitHash(&H);
    for (i = 0; i < N - 1; i++)
    {
        //����ǰN-1����¼
        j = InsertHash(&H, r[i]);
        if (j == DUPLICATE)
            printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼%d\n", r[i].key, r[i].key);

    }//for
    printf("������ϣ��:\n");
    TraverseHash(H, print);
    printf("������Ҫ���ҵĹؼ���: ");
    scanf("%d", &K);
    j = Find(H, K, &p);
    if (j == SUCCESS)
        print(p, H.elem[p]);
    else
        printf("û�ҵ��ùؼ���\n");
    j = InsertHash(&H, r[i]);//�����N����¼
    if (j == 0)//�ؽ���ϣ��
        j = InsertHash(&H, r[i]);//�ؽ���ϣ������²����N����¼
    printf("�����ؽ���Ĺ�ϣ��:\n");
    TraverseHash(H, print);
    printf("����������Ҽ�¼�Ĺؼ���: ");
    scanf("%d",&K);
    j = Find(H, K, &p);
    if (j == SUCCESS)
        print(p, H.elem[p]); 
    else
        printf("û�ҵ�\n");
    DestroyHash(&H);
    system("pause");
    return 0;
}