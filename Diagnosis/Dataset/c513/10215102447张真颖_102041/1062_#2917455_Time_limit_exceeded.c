#include <stdio.h>
#include <stdlib.h>

int count(n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 3;
    else if(n==4) return 5;
    else return count(n-1)+count(n-2)*2+count(n-3)*3+count(n-4)*5;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0,steps=0;
        scanf("%d",&n);
        steps=count(n);
        printf("case #%d:\n%d\n",i,steps);
    }
    return 0;
}