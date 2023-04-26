#include <stdio.h>
int n,t,countt;

void solve(int a,int b)//a=m,b=p
{
    if(a==0)
    {
        if(b==t){countt++;}
        return;
    }
    else
    {
        a--;
        if(b==n){solve(a,b-1);}
        else if(b==1){solve(a,2);}
        else
        {
            solve(a,b-1);
            solve(a,b+1);
        }
    }
}

int main()
{
    int T,m,p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        countt=0;
        solve(m,p);
        printf("%d\n",countt);
    }
    return 0;
}
