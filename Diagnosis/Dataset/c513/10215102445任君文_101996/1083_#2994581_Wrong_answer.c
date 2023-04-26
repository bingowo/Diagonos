#include<stdio.h>
#include<stdlib.h>
void zero()
{
    int n,m=5;
    int res;
    scanf("%d",&n);
    while(n>=m)
    {
        res+=n/m;
        m*=5;
    }
    printf("%d\n",&n);
}
int main()
{
    int T;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        zero();
    }
    return 0;
}