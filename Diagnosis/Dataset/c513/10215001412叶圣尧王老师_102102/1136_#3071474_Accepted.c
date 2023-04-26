#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{   int n,i;
    int a[20001],p[20001],b[20001];
    int n0=0,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0,k=0;i<n;i++)
        if(a[i]==0) p[k++] = i;
    n0 = k;

    for(i=0;i<n;i++)
        if(a[i]==1) p[k++] = i;
    int t=p[0];
    for(i=0;i<n;i++)
    {  b[i] = a[t];
        t = p[t];
    }
 int nzero = 0;
    for(i=0;i<n;i++)     if(b[i]==0) nzero++;
    if(nzero != n0)
    {  printf("-1\n");
        return 0;
    }
   else{ for(i=0;i<n;i++) printf("%d ",b[i]);}
}