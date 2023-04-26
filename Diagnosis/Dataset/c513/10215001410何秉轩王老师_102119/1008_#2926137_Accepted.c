#include <stdio.h>
#include <stdlib.h>

int main()
{   int f(int a,int b);
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",f(x,y));
    }
   return 0;
}


int f(int a,int b)
{
    int j,max=0,a1,b1;
    for(j=0;j<32;j++)
    {
        a1=a%2;
        b1=b%2;
        a=a>>1;
        b=b>>1;
        if(a1!=b1){max++;}
    }
    return max;
}