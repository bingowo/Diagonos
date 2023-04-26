#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if(x<0) x=-x;
    if(y<0) y=-y;
    long long distance=x+y;
    int step=0;
    if(distance %2 !=0)
        {
            for(int j = 1; j <= 64; j++)
            {
                if(distance <= (1LL<< j))
                {
                    step += j;
                    break;
                }
            }
            printf("%d",step);
        }
    else if(distance%2 ==0) printf("-1");




    return 0;
}
