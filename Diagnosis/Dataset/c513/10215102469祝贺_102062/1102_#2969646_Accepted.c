#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
long long getn(long long t){
    return (long long)((sqrt(4*t+1)-1)/2);
}

int main(){
    long long t;scanf("%lld",&t);
    long long n=getn(t),k=t-n*(n+1);
    if(k<=n+1 && n%2==0) printf("(%lld,%lld)",n/2,-n/2+k);
    else if(k>=n+1 && n%2==0) printf("(%lld,%lld)",n/2-k+(n+1),-n/2+(n+1));
    else if(k<=n+1 && n%2==1) printf("(%lld,%lld)",-(n+1)/2,(n+1)/2-k);
    else //(k>=n+1 && n%2==1) 
        printf("(%lld,%lld)",-(n+1)/2+k-(n+1),(n+1)/2-(n+1));
    return 0;
}

