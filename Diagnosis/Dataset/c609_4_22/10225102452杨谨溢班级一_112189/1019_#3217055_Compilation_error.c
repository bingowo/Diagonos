#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void *b)  // 升序
{
    char* A = *(char**)a,B = *(char**)b,
    int aa = strlen(A),bb = strlen(b);
    int aaa = atoi(A),bbb = atoi(B);
    if (aaa<0)  aa-=1;
    if (bbb<0)  bb -= 1;
    if (aa != bb)   return bb-aa;
    else return aaa-bbb;
}

int main()
{
    int L[100009][6];
    int a = 0;
    while (scanf("%s",L[a++]) != EOF);
    qsort(L,n,sizeof(L[0]),cmp);
    for (int i = 0;i<a;++i)
    {
        printf("%s",L[i]);
        if (i != a-1)  printf(" ");}
    }
    return 0;
}
