#include<stdio.h>
#define C 1001
int main()
{
    int T,i,j,x;scanf("%d",&T);
    int a[C],b[C];
    for(i=0;i<C;++i){a[i]=1;b[i]=1;}
    for(i=0;i<C;++i)
    {
        for(j=1;j<501;++j)
        {
            if(i+2*j<C)a[i+2*j]+=b[i];
        }
    }
    for(i=0;i<C;++i)b[i]=a[i];
	for(i=0;i<C;++i)
    {
        for(j=1;j<334;++j)
        {
            if(i+3*j<C)a[i+3*j]+=b[i];
        }
    }
    for(i=0;i<C;++i)b[i]=a[i];
    for(i=0;i<C;++i)
    {
        for(j=1;j<251;++j)
        {
            if(i+4*j<C)a[i+4*j]+=b[i];
        }
    }
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d",&x);
        printf("%d\n",a[x]);
    }
    return 0;
}