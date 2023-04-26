#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    int *a1=(int*)a,*b1=(int*)b;
    int n,m;
    while (*a1>0)
    {
        n=*a1%10;
        *a1=*a1/10;
    }
    while (*b1>0)
    {
        m=*b1%10;
        *b1=*b1/10;
    }
    if (n!=m) return m=n;
    else return *a1-*b1;
}
int main()
{
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N,s[10001]={0};
        scanf("%d",&N);
        for (int j=0;j<N;j++)
        {
            scanf("%d",&s[j]);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf ("case #%d:\n",i);
        for (int j=0;j<N;j++)
        {
            printf("%d%c",s[j],j==N-1?'\n':' ');
        }
    }
    return 0;
}
