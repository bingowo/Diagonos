#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,i,j,k1,k2,len;int a[64],b[64];
    scanf("%d",&T);long long x,y;
    for(i=0;i<T;i++)
    {
        len=0;
        scanf("%lld",&x);scanf("%lld",&y);
        for(k1=0;x>0;k1++)
        {
            a[k1]=x%2;
            x/=2;
        }
        for(k2=0;y>0;k2++)
        {
            b[k2]=y%2;
            y/=2;
        }
        if(k1<k2)for(;k1<k2;k1++)a[k1]=0;
        else for(;k2<k1;k2++)b[k2]=0;
        for(j=0;j<k1;j++)if(a[j]!=b[j])len++;
        printf("%d",len);
    }
}