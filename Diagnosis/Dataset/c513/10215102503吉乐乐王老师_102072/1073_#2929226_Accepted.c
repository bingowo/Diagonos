//1.含9的数的统计 2，9的倍数的统计
//去掉含9的数，剩下的数是连续的9进制数
//f[n]表示9进制数n对应的十进制数（前提是n不含9）
//[a,b]中不含9的数的个数=f(b)-f(a)+1;
//然后还要扣除9的倍数的数
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long N2T(long long a) {
    return (a < 9)? a: N2T(a/10)*9 + a%10;	 // Nine system to Ten system, f in 1096.PPT
}
long long f(long long a) {
    long long d0 = a%10;
    for (long long x = a - d0; x <= a; x++) {	 // g in 1096.PPT
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*N2T(a - a%10)/9;	 // Ans in 1096.PPT
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld", f(b) - f(a) + 1);}
