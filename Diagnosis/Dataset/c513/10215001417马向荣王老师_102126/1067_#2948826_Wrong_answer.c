#include<stdio.h>
int ti(int n)
{
    int t=0.;
    t=floor(0.33622811699494093*pow(1.839286755214161,n)+0.5);
    return t;
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