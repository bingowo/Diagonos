// 任意类型的指针均可以隐式转化为 VOID* 上，但void*必须显示转化为对应类型

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpa(const void*a,const void *b)
{
    if ( *(int*)a != *(int*)b)   return *(int*)a - *(int*)b;
    else *(int*)a = 0;
    return 0;
}
int cmpd(const void*a,const void *b)
{
    if ( *(int*)a != *(int*)b)   return *(int*)b - *(int*)a;
    else *(int*)a = 0;
    return 0;
}
int main()
{
    char c;
    scanf("%c",&c);
    int L[1005];
    int a = 0;
    while (scanf("%d",&L[a++]) != EOF);
    if (c = 'D')   qsort (L,a,sizeof(int),cmpd);
    else  qsort (L,a,sizeof(int),cmpa);
    for (int i = 0;i<a;++i)
    {
        printf("%d",L[i]);
        if (i == a-1)  printf(" ");
    }
    return 0;
}
