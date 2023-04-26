#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    long long int x,y;
    int i;
    scanf("%lld %lld",&x,&y);
    if(x==0&&y==0) {printf("0");return 0;}
    unsigned long long int r=abs(x)+abs(y)+1;
    unsigned long long c=r-1;
    if(c%2)
    {
        for( i=1;i<42;i++)
        {
            if(pow(2,i-1)<r&&r<=pow(2,i))
                {printf("%d",i);
                break;}
       }
    }
    else printf("-1");
    return 0;
}