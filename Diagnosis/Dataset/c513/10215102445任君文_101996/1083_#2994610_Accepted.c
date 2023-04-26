#include<stdio.h>
#include<stdlib.h>
int zero(int n)
{
    if(n<=4)
        return 0;
    else if(n==5)
        return 1;
    else if(n>5)
        return (n/5+zero(n/5));
}
int main()
{
    int T;
    int i,n,res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        res=zero(n);
        printf("%d\n",res);
    }
    return 0;
}