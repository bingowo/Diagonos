#include<stdio.h>
#include<math.h>

typedef long long ll;

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (!n) break;

        double x,a;
        x=n*log10(n);
        x-=(int)x;
        a=pow(10,x);
        printf("%d\n",a);
    }
    return 0;
}