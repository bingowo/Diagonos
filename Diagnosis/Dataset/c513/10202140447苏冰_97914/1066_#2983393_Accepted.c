#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int f(int n,int p,int m,int t)
{
    if(m==0 && p!=t) return 0;
    if(m==0 && p==t) return 1;
    if(m>0 && t==1) return f(n,p,m-1,t+1);
    if(m>0 && t==n) return f(n,p,m-1,t-1);
    else return f(n,p,m-1,t-1)+f(n,p,m-1,t+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,p,m,t;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        if(t>n) printf("0\n");
        else printf("%d\n",f(n,p,m,t));
    }
    return 0;
}


