#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    long long int x,y;
    int steps = 0;
    char step[100];
    scanf("%lld %lld",&x,&y);
    if((abs(x) + abs(y)) % 2 == 0)  
        printf("-1\n");
    if(abs(x) % 2 == 1)
    {
        while(x != 0)
        {
            if((abs(x) + abs(y)) % 2 == 0)
                printf("-1\n");
            if(y == 1)
            {
                y -= 1;
                step[steps++] = 'N';
            }
            else if(y == -1)
            {
                y += 1;
                step[steps++] = 'S';
            }
            if(abs(x + 1) % 2 == 1)
            {
                step[steps++] = 'W';
                x += 1;
                x /= 2;
                y /= 2;
            }
            else
            {
                step[steps++] = 'E';
                x -= 1;
                x /= 2;
                y /= 2;
            }
        }
    } 
    else if(abs(y) % 2 == 1)
    {
        while(y != 0)
        {
            if(x == 1)
            {
                x -= 1;
                step[steps++] = 'E'; 
            }
            else if(x == -1)
            {
                x += 1;
                step[steps++]  = 'W';
            }
            if(abs(y + 1) % 2 == 1)
            {
                step[steps++] = 'S';
                y += 1;
                y /= 2;
                x /= 2;
            }
            else
            {
                step[steps++] = 'N';
                y -= 1;
                y /= 2;
                x /= 2;
            }
        }
    }
    step[steps] = '\0';
    printf("%d\n%s\n",steps,step);
    return 0;
}