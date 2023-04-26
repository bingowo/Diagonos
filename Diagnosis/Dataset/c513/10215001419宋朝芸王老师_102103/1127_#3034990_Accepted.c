#include <stdio.h>
#include <stdlib.h>

long long int GCD(long long int m,long long int n)
{
    long long int temp;
    if(m<n) temp=m,m=n,n=temp;     //m中放较大数
    if(m%n==0) return n;
    temp=n,n=m%n,m=temp;
    return(GCD(m,n));
}

int main()
{
    int R,T;
    scanf("%d",&T);

    long long int up,down;
    scanf("%lld/%lld",&up,&down);

    for(R = 1; R < T; R++){
        long long int temp_up, temp_down;
        scanf("%lld/%lld",&temp_up,&temp_down);
        up = up * temp_down + temp_up * down;
        down *= temp_down;

        long long int gcd = GCD(up,down);
        up = up/gcd;
        down = down/gcd;
    }

    if(down == 1) printf("%lld",up);
    else if(up == 0) printf("0");
    else printf("%lld/%lld",up,down);

    return 0;
}
