#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int count=0;
        void ans(int p,int m,int t,int n)
        {
            if(m==0&&p==t)
            {
                count++;
                return;
            }
            if(m>0)
            {
                if(p==1) ans(2,m-1,t,n);
                else if(p==n) ans(n-1,m-1,t,n);
                else
                {
                    ans(p-1,m-1,t,n);
                    ans(p+1,m-1,t,n);
                }
            }
        }
        ans(p,m,t,n);
        printf("%d\n",count);
    }
}

