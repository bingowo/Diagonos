#include<stdio.h>
#include<string.h>

int solve(int n,int p, int m,int t)
{
    if(m==0)
    {
        if(p==t) return 1;
        else return 0;
    }

    if(p==n)
        return solve(n,p-1,m-1,t);
    else if(p==1)
        return solve(n,p+1,m-1,t);
    else
    {
        return solve(n,p-1,m-1,t)+solve(n,p+1,m-1,t);
    }

}




int main()
{
    int cas;scanf("%d",&cas);
    for (int i =0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        int num;
        num = solve(n,p,m,t);
        printf("%d\n",num);
    }
    return 0 ;
}
