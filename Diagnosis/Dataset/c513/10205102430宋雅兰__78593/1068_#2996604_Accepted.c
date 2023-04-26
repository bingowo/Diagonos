#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int func(int n,int m)
{
    if(n<m)return 0;
    if(n==m)return 1;
    return 2*func(n-1,m)+pow(2,n-m-1)-func(n-m-1,m);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1)
    {
        printf("%d\n",func(n,m));
    }
    
    return 0;
}