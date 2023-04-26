#include <stdio.h>

unsigned long long a,b,ans;
int main(){
    scanf("%lld %lld",&a,&b);
    if(a > b){
        unsigned long long tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while(a&&b){
        ans = ans + 4*a*(b/a);
        b = b%a;
        unsigned long long tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    printf("%lld",ans);
}