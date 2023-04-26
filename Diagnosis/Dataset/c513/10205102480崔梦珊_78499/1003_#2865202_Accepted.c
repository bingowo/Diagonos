#include<stdio.h>
#include<stdlib.h>











int cmp(const void* a,const void* b);
int main()
{
    int T;
    scanf("%d\n",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int g,j;
        scanf("%d\n",&g);
        long long *a;
        a=(long long*)malloc(sizeof(long long)*g);
        for(j=0;j<g;j++)
        {
            scanf("%lld",&a[j]);
        }
        printf("case #%d:\n",i);
        qsort(a,g,sizeof(long long),cmp);
        for(int k=0;k<g;k++)
        {
            printf("%lld ",a[k]);
        }
        printf("\n");
    }
    return 0;
}




int cmp(const void* a,const void* b)
{
    int x=0,y=0;
    long long m,n;
    m=*(long long*)a;
    n=*(long long*)b;
    long long m1,n1;
    m1=m;
    n1=n;
    if (m>=0)
    {
        while(m/2>0)
        {
            x=x+m%2;
            m=m/2;
        }
        x=x+m;
    }
    if (m<0)
    {
        m=-m-1;
        while(m/2>0)
        {
            x=x+m%2;
            m=m/2;
        }
        x=x+m;
        x=64-x;
    }
    if (n>=0)
    {
        while(n/2>0)
        {
            y=y+n%2;
            n=n/2;
        }
        y=y+n;
    }
    if (n<0)
    {
        n=-n-1;
        while(n/2>0)
        {
            y=y+n%2;
            n=n/2;
        }
        y=y+n;
        y=64-y;
    }
    if(x<y){return 1;}
    if(x>y){return -1;}
    else
    {
        if(m1>=n1){return 1;}
        if(m1<n1){return -1;}
    }
}
