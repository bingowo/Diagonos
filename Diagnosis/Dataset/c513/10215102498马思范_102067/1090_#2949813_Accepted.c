#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    double a;
    double p;
    scanf("%d",&n);
    while(n!=0)
    {
        a=n*log10(n);
        a=a-(int)a;
        p= pow(10,a);
        printf("%d\n",(int)p);
        scanf("%d",&n);
    }
    return 0;
}