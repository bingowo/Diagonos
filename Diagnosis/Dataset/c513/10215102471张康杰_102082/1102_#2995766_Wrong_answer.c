#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    long long int input,x,y;
    scanf("%lld",&input);
    long long int root = sqrt(input);
    x = root / 2,y = root / 2 + 1;
    if(root * root + root > input)
    {
        x = x - input - root * root;
        y = y;
    }
    else if(root * root + root + root + 1 > input)
    {
        x = x - root;
        y = y - (input - root * root - root);
    }
    else if(root * root + root + 2 * (root + 1) > input)
    {
        x = x - root;
        y = y - (input - root * root - root);
        x = x + (input - root * root - root - root - 1);
    }
    else
    {
        x = x - root;
        y = y - (input - root * root - root);
        x = x + (input - root * root - root - root - 1);
        y = y + (input - root * root - root - 2 * (root + 1));
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}