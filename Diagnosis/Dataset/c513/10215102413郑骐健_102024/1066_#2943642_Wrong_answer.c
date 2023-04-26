#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int re(int p,int m,int t,int n)
{
   if(abs(p-m)==t)return 1;
   else if(abs(p-m)>t)return 0;
   else
   {
       if(p==1)return re(p+1,m,t-1,n);
       else if(p==n)return re(p-1,m,t-1,n);
        else
       {
           return re(p-1,m,t-1,n)+re(p+1,m,t-1,n);
       }
   }
}
int main()
{
        int cas;
        scanf("%d",&cas);
        for(int i =0;i<cas;i++)
        {
            int n,p,m,t;
            scanf("%d%d%d%d",&n,&p,&t,&m);
            printf("%d\n",re(p,m,t,n));
        }
        return 0;
}

