#include <stdio.h>
#include <string.h>

int N2T(long long a){
    return (a<9)?a:N2T(a/10)*9+a%10;
}   //9进制转10进制

long long f(long long a){
     long long d0 = a%10;
     for(long long x = a-d0;x<=a;x++ ){
         char str[100] = {0};
         sprintf(str,"%lld",x);
         if (x%9 == 0 || strchr(str, '9') != 0) d0--;

     }
    return d0 + 8*N2T(a - a%10)/9;

}

int main(){
    long long b;
    long long a;
    scanf("%lld %lld",&a,&b);
    printf("%lld",f(b)-f(a)+1);
}