#include <stdlib.h>
#include <stdio.h>

void compute(int a, int b);

int main()
{
    int T;
    scanf("%d",&T);
    int a,b;
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&a,&b);
        compute(a, b);
    }
    return 0;
}

void compute(int a, int b)
{
    int c[64]={0};
    int d[64]={0};
    int i=0;
    int num=0;
    int j=0;
    while(a)
    {
        c[i++]= a & 1;
        a>>=1;
    }
    while(b)
    {
        d[j++] = b & 1;
        b>>=1;
    }
    for(int k=0;k<64;k++)
    {
        if(c[k]!=d[k])
            num++;
    }
    printf("%d\n",num);
}