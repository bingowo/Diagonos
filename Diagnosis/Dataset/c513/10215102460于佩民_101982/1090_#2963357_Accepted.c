#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        double a, x;
        a=n*log10(n);
        a-=(int)a;
        x=pow(10, a);
        printf("%d\n",(int)x);
        scanf("%d",&n);
    }
    return 0;
}