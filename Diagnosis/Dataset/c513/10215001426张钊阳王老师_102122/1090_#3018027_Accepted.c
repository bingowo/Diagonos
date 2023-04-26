#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a;
    while(scanf("%d",&a)&&a!=0)
    {
        double f = a*log10(a);
        f -= (int)f;
        int b = pow(10,f);
        printf("%d\n",b);
    }
}
