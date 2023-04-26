#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int n,int m)
{
    if(n==m) return 1;
    else if(n<m) return 0;
    else return 2*f(n-1,m)-f(n-1-m,m)+pow(2,n-1-m);
}

int main()
{
    int n=0,m=0;
    while(1){
        scanf("%d %d",&n,&m);
        if(n==-1) break;
        int ans=0;
        ans=f(n,m);
        printf("%d\n",ans);
    }
    return 0;
}
