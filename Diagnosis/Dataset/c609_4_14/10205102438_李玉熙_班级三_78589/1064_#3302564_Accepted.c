#include<stdio.h>
int main()
{
    long long m,n;
    scanf("%lld%lld",&m,&n);
    m=m>=n?m:n;
    n=m>=n?n:m;
    long long grith=0,dif=1;
    while(dif>0){
        if(m%n==0){
            grith+=m/n*n*4;
            break;
        }
        grith+=4*n;
        dif=m-n;
        m=dif>=n?dif:n;
        n=dif>=n?n:dif;
    }
    printf("%lld",grith);
}