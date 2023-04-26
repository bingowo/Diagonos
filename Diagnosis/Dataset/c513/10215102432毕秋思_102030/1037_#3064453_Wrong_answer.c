#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *q1,const void *q2)
{
    return *(int *)q2-*(int *)q1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[100001]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int b[100000]={0};
    for(int i=0;i<n-1;i++)
    {
        b[i]=a[i]-a[i+1];
    }
    int s=0;
    for(int i=0;i<m-1;i++)
    {
        s+=b[i]*(m-i-1);
    }
    int min=s;
    for(int i=0;i<n-m;i++)
    {
        s-=b[i]*(m-1);
        s+=(a[i+1]-a[i+m]);
        if(s<min)
        min=s;
    }
    printf("%d",min);
    return 0;
}

