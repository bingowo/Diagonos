#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        if(!n)
            return 0;
        
        double f = n*log10(n);
        f -= (int)f;
        int b = pow(10,f);
        printf("%d\n",b);
    }
}
