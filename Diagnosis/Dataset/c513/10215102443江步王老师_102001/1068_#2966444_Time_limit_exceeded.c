#include<stdio.h>

void solve(int n,int m);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while (n>0 && m>0)
    {
        solve(n,m);
        scanf("%d %d",&n,&m);
    }

    return 0;
}


void solve(int n,int m)
{
    int a=~((-1)<<n);
    int t=0;
    int num=0;
    int temp=0;
    int i=0;
    
    
    while (i++ < m)//生成长度为m的全1序列
    {
        t=(t<<1)+1;
    }

    
    while (a >= 0)
    {
        temp=t;
        for (i=0;i<n-m;i++)
        {
            if ((temp&a) == temp)
            {
                num++;
                break;
            }
            temp=temp<<1;
        }
        a--;
    }

    printf("%d\n",num);
    return;
}