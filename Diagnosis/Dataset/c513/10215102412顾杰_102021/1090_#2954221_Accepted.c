#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    while(1)
    {
        double n;
        scanf("%lf",&n);
        if(n==0)break;
        n=n*log10(n);
        n-=(int)n;
        printf("%d\n",(int)pow(10,n));
    }
}

