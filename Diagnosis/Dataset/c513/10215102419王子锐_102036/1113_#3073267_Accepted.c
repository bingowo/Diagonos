#include<stdio.h>
#define C 101
#define L 32
void add(int* a,const int* b)
{
    int i,carry=0,tmp;
    for(i=L-1;i>-1;--i)
    {
        tmp=a[i]+b[i]+carry;
        a[i]=tmp%10;
        carry=tmp/10;
    }
}
int main()
{
    int a[C][L]={0},i,j,k,n;scanf("%d%d",&k,&n);
    a[1][L-1]=1;
    for(i=2;i<n;++i)
    {
        if(i<k)for(j=0;j<i;++j)add(a[i],a[j]);
        else for(j=i-k;j<i;++j)add(a[i],a[j]);
    }
    for(i=0;i<L;++i)if(a[n-1][i])break;
    if(i==L)printf("0");
    else for(i;i<L;++i)printf("%d",a[n-1][i]);
    return 0;
}
