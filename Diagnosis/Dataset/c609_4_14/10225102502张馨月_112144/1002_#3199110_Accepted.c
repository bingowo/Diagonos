#include <stdio.h>
int main( )
{
    int t;
    long long int n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
       scanf("%lld",&n);
       int a=n%2,b;
       int l=1,sum=1;
       while(n>0)
       {
            n=n/2;
            b=n%2;
            if(a!=b){l++;}
            else
            {
                if(l>sum) sum=l ;
                l=1;
            }
            a=b;
       }
   if (l>sum)
    {l--;
   sum=l;
    }
    printf("case #%d:\n",i);
    printf("%d\n",sum);
    }

return 0;
}
