#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int m;
    scanf("%d",&m);
    int a[1100]={0},p;
    for(int i=0,p=1100;i<m;i++,p--)
    {
        int l;
        scanf("%d",&l);
        a[l]=p;
        
    }
    int n;
    scanf("%d",&n);
    int b[n+1];
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
    int cmp(const void*a1,const void*a2)
{
    int m=*(int*)a1;
    int n=*(int*)a2;
    if(a[n]!=a[m])return a[n]-a[m];
    else return m-n;
}
    qsort(b,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
    printf("%d ",b[i]);
    return 0;
}