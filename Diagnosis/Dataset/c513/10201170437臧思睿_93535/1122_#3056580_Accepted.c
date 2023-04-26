#include <stdio.h>
#include <math.h>

int main()
{
    int t,d,i;
    scanf("%d",&t);
    while(t--)
    {
        long long int n=0;
        scanf("%lld",&n);
        if(n==0){printf("0");}
        else
        {
            for(i=0;i<5;i++)
            {
                d=(int)(log10((double)n)/log10(2333))+1;
            }
            int a[d];
            for(i=0;i<d;i++)
            {
                a[i]=n%2333;
                n/=2333;
            }
            for(i=0;i<d;i++)
            {
                printf("%d ",a[d-i-1]);
            }
        }
        printf("\n");
    }
    return 0;
}

