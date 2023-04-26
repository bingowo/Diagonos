#include<stdio.h>
int pow(int a,int b)
{
    int ans=1;
    for(int i=0;i<b;i++)ans*=a;
    return ans;
}
int main()
{
    int T,cas,n;scanf("%d",&T);
    for(cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%d\n",cas,pow(2,n));
    }
    return 0;
}