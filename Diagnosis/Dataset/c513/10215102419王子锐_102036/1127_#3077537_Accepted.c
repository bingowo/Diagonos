#include<stdio.h>

int gcd(int a,int b)//求最大公约数 
{
    return b?gcd(b,a%b):a;
}

int main()
{
    int n;
    scanf("%d",&n);
    int numerator=0,denominator=1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d/%d",&a,&b);
        numerator=numerator*b+denominator*a;
        denominator=denominator*b;
        int g=gcd(numerator,denominator);
        numerator=numerator/g;
        denominator=denominator/g;
    }
    printf("%d/%d",numerator,denominator);
    return 0;
}