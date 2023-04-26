#include<stdio.h>
#define C 1001
int main()
{
    int f[C],y0[C]={0},x0[C]={0},w0[C]={0},i,j,k,w,x,y;
    for(i=0;i<C;++i)
        if(!(i%4))w0[i]+=1;
    for(i=0;i<251;++i)
    {
        for(j=0;j<334;++j)
            if(4*i+3*j<C)x0[4*i+3*j]+=1;
    }
    for(i=0;i<251;++i)
    {
        for(j=0;j<334;++j)
        {
            for(k=0;k<501;++k)
                if(4*i+3*j+2*k<C)y0[4*i+3*j+2*k]+=1;
        }
    }
    f[0]=1;f[1]=1;f[2]=2;f[3]=3;f[4]=5;
    for(i=5;i<C;++i)f[i]=f[i-1]+y0[i-2]+x0[i-3]+w0[i-4];
    int T,n;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d",&n);
        printf("%d",f[n]);
    }
    return 0;
}