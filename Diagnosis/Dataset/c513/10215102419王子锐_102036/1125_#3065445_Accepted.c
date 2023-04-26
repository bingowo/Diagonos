#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define LL long long
LL gcd(LL a,LL b)
{
    return (b?gcd(b,a%b):a);
}
int main()
{
    
int T;scanf("%d",&T);
for (int t = 0; t < T; ++t)
{
char a[20];scanf("%s",a);
int len = strlen(a);
LL integer=0, decimal=0, cyclic=0, denominator=1,q=0;
int i=0,cnt=0;
for (i=0;i<len;++i){//整数部分
if (a[i] == '.') break;
integer = integer * 10 +a[i]-'0';
}
for (++i;i<len;++i){ //小数非循环部分
if (a[i] == '[') break;
decimal = decimal * 10 + a[i] - '0';
denominator = denominator * 10;
}
for (++i;i<len;++i){//小数循环节部分
if (a[i] == ']') break;
cyclic = cyclic * 10 + a[i] - '0';
q=q*10+9;
cnt=cnt+1;
}
if (q!=0)//有循环节，0.12[1]=(121-12)/900
{
LL p=1;
while(cnt--)p=p*10;
decimal=decimal*p+cyclic-decimal;
denominator=q*denominator;
}
LL m = gcd(decimal, denominator);
decimal = decimal/m;
denominator = denominator / m;
decimal= integer * denominator + decimal;
printf("case #%d:\n%lld/%lld\n", t,decimal,denominator);
}
return 0;
}
