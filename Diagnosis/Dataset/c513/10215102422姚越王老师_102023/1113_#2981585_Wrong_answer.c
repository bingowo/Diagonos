#include<stdio.h>
#define C 101
__int128 a[C]={0};
int main()
{
    int k,n,i,j;scanf("%d%d",&k,&n);
    a[0]=0;a[1]=1;
    for(i=2;i<n;++i)
    {
        if(i<k)for(j=0;j<i;++j)a[i]+=a[j];
        else for(j=i-k;j<i;++j)a[i]+=a[j];
    }
    printf("%I128d",a[n-1]);
    return 0;
}