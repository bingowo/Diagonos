#include<stdio.h>
long long tribonacci[74];
int main()
{
    int T,n,i;
    scanf("%d",&T);
    tribonacci[0]=0;
    tribonacci[1]=1;
    tribonacci[2]=1;
    for(i=3;i<74;i++)
    {
        tribonacci[i]=tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3];
    }
    for(n=0;n<T;n++)
    {
        int tn;
        scanf("%d",&tn);
        printf("case #%d:\n%lld\n",n,tribonacci[tn]);
    }
    return 0;
}