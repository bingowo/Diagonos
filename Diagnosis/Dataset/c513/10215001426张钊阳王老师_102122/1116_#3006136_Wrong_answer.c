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
    if(distance % 2)
        {
            for(int j = 1; j <= 64; j++)
            {

                if(distance <= (1<< j))
                {
                    step += j;
                    break;
                }
            }
        }

    printf("%lld",step);


    return 0;
}
