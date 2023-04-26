#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    long long int input,x,y;
    scanf("%lld",&input);
    long long int root = sqrt(input);
    if(root % 2 == 1)
    {
        x = root / 2;
        y = root / 2 + 1;
        if(root * root + root > input)
        {
            x = x - (input - root * root);
            y = y;
        }
        else
        {
            x = x - root;
            y = y - (input - root * root - root);
        }
    }
    else 
    {
        x = -root / 2;
        y = x;
        if(root * root + root > input)
        {
            x = x + (input - root * root);
            y = y;
        }
        else
        {
            x = x + root;
            y = y + (input - root * root - root);
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}