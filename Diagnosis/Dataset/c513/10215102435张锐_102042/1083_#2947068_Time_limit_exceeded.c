#include <stdio.h>
#include <stdlib.h>
long long unsigned f(n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    else return n*f(n-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long unsigned temp=f(n);
        int num=0;
        while(temp%10==0) num++;
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}