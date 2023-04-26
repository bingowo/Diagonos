#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 1000000

typedef long long int lli;

lli square (lli x,lli y)
{
    if(x==y) return 4*x;
    lli min = x>y?y:x;
    if (min==x) return 4*min+square(x,y-min);
    else return 4*min+square(x-min,y);
}




int main(void)
{
    lli x,y;
    scanf("%lld%lld",&x,&y);
    lli ans=square(x,y);
    printf("%lld",ans);
    return 0;

}
