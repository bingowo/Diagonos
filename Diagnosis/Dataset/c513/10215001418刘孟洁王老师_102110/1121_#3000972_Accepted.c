#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**/
int main()
{
    int n,i,h,a,sum,max;
    int s[107],ans[1007];
    scanf("%d",&n);
    for(i = 0; i < n; i++)scanf("%d",&s[i]);
    memset(ans,0,sizeof(ans));
    for(i = 0,max = 0; i < pow(3,n); i++)
    {
        a = i;
        for(h = n-1,sum = 0; h >= 0; h--)
        {
            if(a%3 == 2)sum -= s[h];//就像求二进制一样求该位的数，2代表-1；
            else if(a%3 == 1)sum += s[h];//用三进制来记录每个数前面的系数，2代表-1；
            a /= 3;
            if(!a)break;
        }
        if(sum > 0)ans[sum] = 1;
        if(max < sum)max = sum;
    }
    for(i = 1; i <= max; i++)printf("%d",ans[i]);
    return 0;
}