#include <stdio.h>

int f(int n,int p,int m,int t)
{
    if(m == 0 && p == t)
    {
        return 1;
    }
    else if(m == 0 && p != t)
    {
        return 0;
    }
    if(p == 1)
    {
        return f(n,p+1,m-1,t);
    }
    if(p == n)
    {
        return f(n,p-1,m-1,t);
    }
    else
    {
        return f(n,p-1,m-1,t) + f(n,p+1,m-1,t);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",f(n,p,m,t));
    }
    return 0;
}


