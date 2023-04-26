#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int re(int m,int n)
{
    if(m==n)return 1;
    else if(m > n)return 0;
    else
    {
    int z=1;
    for(int i =0;i<n-m-1;i++)
    {
        z*=2;
    }
    return 2*re(m,n-1)+ z-re(m,n-m-1);
    }
}
int main()
{


    int m =0,n=0;
    while(n!=-1||m!=-1)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",re(m,n));
    }
        return 0;
}

