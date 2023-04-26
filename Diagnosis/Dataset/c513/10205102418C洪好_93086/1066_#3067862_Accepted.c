#include <stdio.h>
#include <stdlib.h>

int f(int n, int p, int m, int t)
{
    if(m == 0)
    {
        if(p == t) return 1;
        else return 0;
    }
    else
    {
        if(p==1) return f(n,2,m-1,t);
        else if(p==n) return f(n,p-1,m-1,t);
        else
        {
            return f(n,p-1,m-1,t) + f(n,p+1,m-1,t);
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d", &n, &p, &m, &t);
        printf("%d\n",f(n,p,m,t));
    }
    return 0;
}