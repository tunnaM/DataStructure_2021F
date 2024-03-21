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
        //插入前N-1个记录
        j = InsertHash(&H, r[i]);
        if (j == DUPLICATE)
            printf("表中已有关键字为%d的记录，无法再插入记录%d\n", r[i].key, r[i].key);

    }//for
    printf("遍历哈希表:\n");
    TraverseHash(H, print);
    printf("请输入要查找的关键字: ");
    scanf("%d", &K);
    j = Find(H, K, &p);
    if (j == SUCCESS)
        print(p, H.elem[p]);
    else
        printf("没找到该关键字\n");
    j = InsertHash(&H, r[i]);//插入第N个记录
    if (j == 0)//重建哈希表
        j = InsertHash(&H, r[i]);//重建哈希表后重新插入第N个记录
    printf("遍历重建后的哈希表:\n");
    TraverseHash(H, print);
    printf("请输入待查找记录的关键字: ");
    scanf("%d",&K);
    j = Find(H, K, &p);
    if (j == SUCCESS)
        print(p, H.elem[p]); 
    else
        printf("没找到\n");
    DestroyHash(&H);
    system("pause");
    return 0;
}