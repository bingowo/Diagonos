#include <stdio.h>
#include <math.h>
int f(int n)
{
   if(n==1) return 2;
   if(n==2) return 4;
   else
        return 2*f(n-1)-(f(n-1)+1)/4;
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==-1)break;
        else
            printf("%d\n",f(n));
    }
    return 0;
}
