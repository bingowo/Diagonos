#include <stdio.h>
#include <math.h>

int main()
{
    int count,count1,n;
    long long int x;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%d",&n);
        x=pow(2,n);
        printf("case #%d:\n",count1-count-1);
        printf("%lld\n",x);

    }
}
