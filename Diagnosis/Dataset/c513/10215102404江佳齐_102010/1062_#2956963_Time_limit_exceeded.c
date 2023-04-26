#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else if(n==4) return 8;
    else return (f(n-1)+f(n-2)+f(n-3)+f(n-4));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,sum;
        scanf("%d",&n);
        sum=f(n);
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
