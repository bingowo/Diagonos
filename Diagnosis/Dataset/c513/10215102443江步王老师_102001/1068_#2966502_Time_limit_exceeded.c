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
    int t=~((-1)<<m);
    int num=0;
    int temp=0;
    int i=0;
    
    
    t=~((-1)<<m);

    
    while (a >= 0)
    {
        temp=t;
        for (i=0;i<n-m+1;i++)
        {
            if ((temp&a) == temp)
            {
                //printf("a=%d\n",a);
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