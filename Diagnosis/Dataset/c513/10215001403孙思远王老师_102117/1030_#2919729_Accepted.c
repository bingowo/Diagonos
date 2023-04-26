#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    long long int p1,p2,b1,b2;
    p1=*(long long int *)a;
    p2=*(long long int *)b;
    b1=*(long long int *)a;
    b2=*(long long int *)b;
    if(b1<0)
        b1*=-1;
    if(b2<0)
        b2*=-1;
    while(b1>=10)
    {
        b1/=10;
    }
    while(b2>=10)
    {
        b2/=10;
    }
    if(b1>b2)
        return -1;
    else if(b2>b1)
        return 1;
    else if(p1>p2)
        return 1;
    else
        return -1;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,i;
        scanf("%d",&n);
        long long int x[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x[i]);
        }
        qsort(x,n,sizeof(x[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("%lld",x[i]);
            if(i<n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
