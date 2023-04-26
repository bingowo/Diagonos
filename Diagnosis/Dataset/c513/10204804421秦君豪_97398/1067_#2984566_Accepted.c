#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef long long int lli;

lli Tb[74]={0};


lli T(lli n)
{
//    printf("pass");
    if(n==1) return 1;
    else if(n==2) return 1;
    else if(n==0) return 0;
    else if(Tb[n]!=0) return Tb[n];
    else
    {
        lli ans=T(n-1)+T(n-2)+T(n-3);
        Tb[n-1]=T(n-1);
        Tb[n-2]=T(n-2);
        Tb[n-3]=T(n-3);
        return ans;
    }

}

int main(void)
{
    int t;
    lli n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",T(n));
    }

    return 0;

}
