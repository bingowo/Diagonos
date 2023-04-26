#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int C(int n,int m)
{
    int result=1;
    for(int i=1;i<m;i++)
    {
        result=result*n/i;
        i++;
        n--;
    }
    return result;
}
int main()
{
    int n;
    int m;
    scanf("%d%d",&n,&m);
    int a[n];
    int b[n-m+1];
    int c[C(n,m)];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i])
    }
    qsort(a,n,sizeof(int),cmp)
    int q=0;
    for(int j=0;j<n-m+1;j++)
    {
        for(int k=0;k<m;k++)
        {
            q=q+a[m-1]-a[k];
        }
        b[j]=q;
    }
    qsort(b,n-m+1,sizeof(int),cmp)
    printf("%d",b[0]);
    return 0;
}