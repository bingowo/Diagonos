#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
long long uabs(long long a, long long b){
    if(a < 0)a = -a;
    if(b < 0)b = -b;
    return a + b;
}
int power(long long a){
    long long wide = 1, n = 0;
    while(a != 0){
        a /= 2; n++;//printf("%d\n", n);
    }
    return n;
}
int main(){
	int i = 0, ans = 0;
    long long n, m; 
    scanf("%lld%lld", &n, &m);
    ans = uabs(n, m);//printf("%lld\n", n);
    if(ans%2)printf("%d", power(ans));
    else printf("-1");
    system("pause");
	return 0;
} 