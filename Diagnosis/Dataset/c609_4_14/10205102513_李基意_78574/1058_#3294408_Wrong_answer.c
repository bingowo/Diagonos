#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n;
    int d,a[100]={0},cnt=0;
    scanf("%lld",&n);
    if(!n) printf("%lld",n);
    else{
        while(n){
            d=n%(-2);
            n=n/(-2);
            if(d<0){
                n++;
                d=2+d;
            }
            a[cnt++]=d;
        }
    }
    for(int i=cnt-1;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}
