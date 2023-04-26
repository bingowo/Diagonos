#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long int N2T(long long int a){
    return (a<9)?a:N2T(a/10)*9+a%10;
}
long long int f(long long int a){
    long long int d0=a%10;
    for(long long int x=a-d0;x<=a;x++){
        char str[100]={0};
        sprintf(str,"%lld",x);
        if(x%9==0||strchr(str,'9')!=0)d0--;
    }
    return d0+8*N2T(a-a%10)/9;
}

int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",f(b)-f(a)+1);
}
