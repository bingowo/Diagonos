#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long int lli;

lli Tb[51] = {0,1,2,4,8};

lli T(lli n)
{
    if (n==0) return 0;
    else if (n==1) return 1;
    else if (n==2) return 2;
    else if (n==3) return 4;
    else if (n==4) return 8;
    else
    {
        lli t1 = (Tb[n-1]==0?T(n-1):Tb[n-1]);
        lli t2 = (Tb[n-2]==0?T(n-2):Tb[n-2]);
        lli t3 = (Tb[n-3]==0?T(n-3):Tb[n-3]);
        lli t4 = (Tb[n-4]==0?T(n-4):Tb[n-4]);
        lli ans = t1 + t2 + t3 + t4;
        Tb[n] = ans;
        return ans;
    }
}

int main()
{
    int t;
    lli n;
    scanf("%d",&t);

    for (int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        printf("case #%d:\n", i);
        printf("%lld\n",T(n));
    }
    return 0;
}
