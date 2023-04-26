#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int solve(int n,int m)
{
    if(n<m)return 0;
    if(n==m)return 1;
    return 2*solve(n-1,m)-solve(n-m-1,m)+(1<<(n-m-1));
}
int main()
{
    int n,m;
    while(scanf("%d",&n)!=-1&&scanf("%d",&m)!=-1){
        if(n!=-1)
            printf("%d\n",solve(n,m));
        
    }
    return 0;
}
