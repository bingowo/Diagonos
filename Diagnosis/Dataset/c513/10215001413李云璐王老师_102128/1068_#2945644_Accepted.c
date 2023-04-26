#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int shu(int n,int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    return 2*shu(n-1,m)+pow(2,n-m-1)-shu(n-m-1,m);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==-1&&m==-1) break;
        else printf("%d\n",shu(n,m));
     }
    return 0;
}