#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void *b)  // 升序
{
    return *(int*)a - *(int*)b;
}

int main()
{

    int L[][6];
    int a = 0;
    while (scanf("%s",L[a++]) != EOF);
    qsort(L,n,sizeof(int),cmp);
    for (int i = 0;i<a;++i)
    {
        printf("%s",L[i]);
        if (i != a-1)  printf(" ");}
    }
    return 0;
}
