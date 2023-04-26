#include <stdio.h>
int main()
{long long int a,B[300];
int T,u,p;
scanf("%d",&T);
for(int i=0;i<=T-1;i++)
{scanf("%lld",&a);
    u=0;
if(a!=0){while(a!=0)
    {B[u]=a%2333;
     a/=2333;
     u++;}
     for(int p=u-1;p>=0;p--)
     {printf("%lld ",B[p]);}
     }
else printf("0");

printf("\n");
}
return 0;
}
