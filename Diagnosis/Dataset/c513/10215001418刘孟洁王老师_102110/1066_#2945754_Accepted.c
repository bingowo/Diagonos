#include <stdio.h>
#include <stdlib.h>
int ways(int n,int p,int m,int t)
{
   if(m == 0 && p == t)return 1;
   else if(m == 0 && p != t)return 0;
   if(p == 1)return ways(n,p+1,m-1,t);
   else if(p == n)return ways(n,n-1,m-1,t);
   else return ways(n,p+1,m-1,t)+ways(n,p-1,m-1,t);
}

int main()
{
    int n,p,m,t,cas,i;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",ways(n,p,m,t));
    }
    return 0;
}
