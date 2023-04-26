#include<stdio.h>
int ti(int n)
{
    int t=0.;
    if(n<=1) return n;
    if(n==2) return 1;
    return ti(n-1)+ti(n-2)+ti(n-3);
}
int main()
{
    int T=0;
    int j=0;
    scanf("%d\n",&T);
    for(j=0;j<T;j++)
    {
        int n=0;
        scanf("%d\n",&n);
        int re=ti(n);
        printf("case #%d:\n",j);
        printf("%d\n",re);
    }
    return 0;
}