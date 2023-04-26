#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int GCD(long long int x,long long int y)
{
    if(x%y == 0)
        return y;
    else
        return GCD(y,x%y);
}
int main()
{
    char input[31];
    int table[3] = {0,1,-1};
    scanf("%s",input);
    char*pt1,*pt2;
    int power1=0,power2=0;
    long long int left=0,right=0;
    pt1 = pt2 = input;
    while(*pt2 != '.')
    {
        pt2++;
    }
    while(*pt1 != '.')
    {
        left = table[*pt1 - '0'] + left*3;
        power1++;
        pt1++;
    }
    pt2++;
    power2++;
    while(*pt2)
    {
        right = right*3 + table[*pt2 - '0'];
        pt2++;
        power2++;
    }
    printf("%lld %lld %lld",left,right/GCD(right,(int)pow(3,power2)),(int)pow(3,power2)/GCD(right,(int)pow(3,power2)));
    return 0;
}