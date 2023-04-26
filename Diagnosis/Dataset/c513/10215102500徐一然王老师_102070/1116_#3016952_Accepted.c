#include <stdio.h>
#include <math.h>

int main()
{
    long long int x,y,sum;
    int n=1;
    scanf("%lld %lld",&x,&y);
    if(x<0)x=-x;
    if(y<0)y=-y;
    sum=x+y;
    if(x==0&&y==0)
    {
        printf("0");
        return 0;
    }
    else if((x+y)%2==0)
    {
        printf("-1");
        return 0;
    }

    while(n)
    {
        if(sum<pow(2,n))
        {
            break;
        }
        n++;
    }
    printf("%d",n);
}
