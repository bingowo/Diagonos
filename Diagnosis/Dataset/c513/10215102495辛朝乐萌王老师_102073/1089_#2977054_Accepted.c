#include <stdio.h>
#include <string.h>
#define LEN 1000

typedef long long int lli;

lli fpow(lli a,lli b,lli m)
{
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a%m;
    }
    else{
        a%=m;
        if (b%2==0) {
            lli temp=(fpow(a, b/2, m)%m);
            return (temp*temp)%m;
        }
        else{
            return ((fpow(a, b-1, m)%m)*(a%m)%m);
        }
    }
}

int main(void){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        lli a,b,n;
        scanf("%lld %lld %lld",&a,&b,&n);
        lli multi=1;
        for (int i=0; i<n; i++) {
            multi*=10;
        }
        printf("case #%d:\n",i);
        printf("%0*lld\n",n,fpow(a, b, multi));
    }
    return 0;
}
