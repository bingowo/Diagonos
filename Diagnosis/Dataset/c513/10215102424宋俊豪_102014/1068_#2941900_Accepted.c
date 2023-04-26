#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(int n,int m)
{
    if(n<m) return 0;
    else if(n==m) return 1;
    return 2*f(n-1,m)-f(n-m-1,m)+(1<<(n-m-1));
}
int main()
{
    int n,m;
    long long int a[3];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        a[0]=0;
        if(n==-1&&m==-1)
            break;
        printf("%d\n",f(n,m));
    }
}
