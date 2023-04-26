#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    double a;
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        if(n%10 == 0){printf("1\n");continue;}
        a = n*log10(n);
        a = a - (int)a;
        printf("%d\n",(int)pow(10,a));
    }
    return 0;
}
