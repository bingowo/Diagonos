#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int main()
{
    int i,j,t=0,T;
    scanf("%d\n",&T);
    while(t++<T)
    {
        ll a;
        int count=0,count1=0;
        scanf("%lld",&a);
        while(a>>1)
        {
            if((a&1)^((a>>1)&1)!=0)
            {
                count1++;
                count=count>=count1?count:count1;
            }
            else{count1=0;}
            a>>=1;
        }
        printf("case #%d:\n%d\n",t-1,count+1);
    }
}
