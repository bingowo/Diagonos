#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    int *a1=(int*)a,*b1=(int*)b;
    int p=abs(*a1),q=abs(*b1);
    int n,m;
    while (p>0)
    {
        n=p%10;
        p/=10;
    }
    while (q>0)
    {
        m=q%10;
        q/=10;
    }
    if (n!=m) return m-n;
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
