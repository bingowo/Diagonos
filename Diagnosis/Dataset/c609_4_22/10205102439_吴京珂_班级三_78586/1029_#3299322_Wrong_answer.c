#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int m=1;
int a[505]={0};
int f(int x)
{
    for(int i=0;i<m;i++)
    {
        if(x==a[i]) return i;
    }
    return m;
}

int cmp(const void* a,const void* b)
{
    int p1=*(int *)a;
    int p2=*(int *)b;
    int q1=f(p1);
    int q2=f(q2);
    if(q1<m||q2<m) return q1-q2;
    else return p1-p2;
}

int main()
{
    int i,n;
    int b[505]={0};

    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

    qsort(b,n,sizeof(b[0]),cmp);
    for(i=0;i<n-1;i++)
    {
        printf("%d ",b[i]);
    }
    printf("%d\n",b[n-1]);

    return 0;
}
