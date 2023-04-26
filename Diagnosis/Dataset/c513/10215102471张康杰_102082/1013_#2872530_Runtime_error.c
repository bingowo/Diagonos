#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int GCD(long long int x,long long int y)
{
    int temp;
    if(x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
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
    while(*pt2 != '.' && *pt2)
    {
        pt2++;
    }
    while(*pt1 != '.' && *pt1)
    {
        left = table[*pt1 - '0'] + left*3;
        power1++;
        pt1++;
    }
    pt2++;

    while(*pt2)
    {
        power2++;
        right = right*3 + table[*pt2 - '0'];
        pt2++;

    }
    int m = (int)pow(3,power2);
    int n;
    if(right < 0)
        n = GCD(-right,m);
    else
        n = GCD(right,m);
    if(left == 0 || right == 0)
        printf("%lld %lld",right/n,m/n);
    else if(left > 0 && right < 0)
        printf("%lld %lld %lld",left-1,(m+right)/n,m/n);
    else if(left < 0 && right > 0)
        printf("%lld %lld %lld",left+1,(m-right)/n,m/n);
    else if(left > 0 && right > 0)
        printf("%lld %lld %lld",left,right/n,m/n);
    else if(left < 0 && right < 0)
        printf("%lld %lld %lld",left,right/n,m/n);
    return 0;
}