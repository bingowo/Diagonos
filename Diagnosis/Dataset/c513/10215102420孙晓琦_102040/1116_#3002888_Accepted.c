#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int subpower(int x)
{
    long long int sum=pow(2,x)-1;
    return sum;
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    if((llabs(x)+llabs(y))%2==0 && !(x==0&&y==0))
    {
        printf("-1");
        return 0;
    }
    if(x==0&&y==0)
    {
        printf("0");return 0;
    }
    for(int i=3;;i++)
    {
        long long int left=subpower(i-1),right=subpower(i);
        if(left<(llabs(x)+llabs(y)) && right>=((llabs(x)+llabs(y))))
                 {
                     printf("%d",i);
                     return 0;
                 }
        else if(left==(llabs(x)+llabs(y)))
        {
            printf("%d",i-1);
            return 0;
        }
    }
}
