#include<stdio.h>


long long stair(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else if(n==4) return 8;
    else return stair(n-1)+stair(n-2)+stair(n-3)+stair(n-4);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",t,stair(n));
    }
}