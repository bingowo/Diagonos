#include<stdio.h>
int f(int n,int m)
{
    if(m>n)return 0;
    if(m==n)return 1;
    return 2*f(n-1,m)+(1<<(n-m-1))-f(n-1-m,m);


}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==-1&&n==-1)break;

        printf("%d\n",f(n,m));
    }
    return 0;



}
