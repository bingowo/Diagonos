// 任意类型的指针均可以隐式转化为 VOID* 上，但void*必须显示转化为对应类型

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpa(const void*a,const void *b)  // 升序
{
    return *(int*)a - *(int*)b;
}
int cmpd(const void*a,const void *b)  // 降序
{
    return *(int*)b - *(int*)a;
}
int main()
{
    char c;
    scanf("%c",&c);
    int L[1005];
    int a = 0;
    while (scanf("%d",&L[a++]) != EOF);
    if (c == 'D')   qsort (L,a,sizeof(int),cmpd);
    else  qsort (L,a,sizeof(int),cmpa);
    for (int i = 0;i<a;++i)
    {
        if (i == 0)   
        {printf("%d",L[i]);if (i != a-1)  printf(" ");}
        else if (L[i] != L[i-1])  
        {printf("%d",L[i]);
        if (i != a-1)  printf(" ");}
    }
    return 0;
}
