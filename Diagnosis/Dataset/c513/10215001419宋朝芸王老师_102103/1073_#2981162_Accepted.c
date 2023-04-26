#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int N2T(long long int a){
    if(a < 9) return a;
    return N2T(a/10)*9 + a%10;
}

long long int g(long long int a){
    long long int temp = a%10;

    for(long long int x = a - temp; x <= a; x++){
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str,'9') != 0) temp--;
    }

    return temp + 8*N2T(a - a%10)/9;
}


int main()
{
    long long int a,b,ans;
    scanf("%lld%lld",&a,&b);

    ans = g(b) - g(a) + 1;
    printf("%lld",ans);

    return 0;
}
