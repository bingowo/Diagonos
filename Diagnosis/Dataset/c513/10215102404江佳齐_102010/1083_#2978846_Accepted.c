#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int func(int n)
{
    if(n<5) return 0;
    else return(n/5+func(n/5));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n,m;
        scanf("%d",&n);
        m=func(n);
        printf("%d\n",m);
    }
    return 0;
}
