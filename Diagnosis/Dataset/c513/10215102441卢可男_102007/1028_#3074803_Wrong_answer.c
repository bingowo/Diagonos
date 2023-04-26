#include <stdio.h>
#include <stdlib.h>

int cmp_A(const void *a, const void *b) //排序规则
{
    return *(int *)a - *(int *)b;
}

int cmp_D(const void *a, const void *b) //排序规则
{
    return *(int *)b- *(int *)a;
}
int main()
{
    char c;
    int m,n;//A/D,digit,中间量
    int b[1000]={0};
    int a[101];
    int j=0;
    scanf("%c",&c);
    while(scanf("%d",&m)!=EOF)
    {
        if(b[m]==0)
        {
            b[m]=1;
            a[j]=m;
        }
         j++;
    }//quchong
    n=j-1;
    if(c=='A')
        qsort(a,n,sizeof(a[0]),cmp_A);

    else
         qsort(a,n,sizeof(a[0]),cmp_D);
    for(int i=0; i<n; i++) //输出去重排序后的序列
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
