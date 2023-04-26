#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int reverse(int a)
{
    int n =0;
    int a_=a;
    while(a_/10!=0)
    {
        n++;
        a_/=10;
    }
    int b=0;
    int base = 10;
    for(int m =n;m>=0;m--)
    {
        b*=10;
        b+= a%base/(base/10);
        base=base*10;
    }
    return b;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    b=reverse (a);
    int n =0;
    while(a!=b)
    {
        a = a+b;
        b=reverse(a);
        n++;
    }
    printf("%d %d",n,a);
    return 0;
}

