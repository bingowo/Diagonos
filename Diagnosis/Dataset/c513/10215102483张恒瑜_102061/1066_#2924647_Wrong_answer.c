#include<stdio.h>
int cas[110][110]={{0}},n;
int cal(int m,int t)
{
    if(t==0 || t>n) return 0;
    else if(m==0) return cas[m][t];
    else return cal(m-1,t-1)+cal(m-1,t+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        cas[0][p]=1;
        printf("%d\n",cal(m,t));
    }
}