#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long NtT(long long a)//9进制转10进制 
{
	return (a<9)?a:NtT(a/10)*9+a%10;
}

long long f(long long a) {
    long long d0 = a%10;//0到a，每九个数分一组，最后一组数 a-d0到a ,0~8，10~18，20~28 
    long long x;
    for ( x = a - d0; x <= a; x++) {
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*NtT(a - a%10)/9;//前面每组9个必有一个被整除； 
}

int main()
{    long long a,b;
	scanf("%lld %lld",&a,&b);
	long long ans=f(b)-f(a)+1;
	printf("%lld",ans);
	return 0;
}