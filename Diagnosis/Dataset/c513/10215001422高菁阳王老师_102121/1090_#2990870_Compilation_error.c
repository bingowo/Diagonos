#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
long long n,result;
double x,y;
while(scanf("%lld",&n)!=EOF&&n!=0)
{undefined
x=n*log10(n);
y=(long long)x; // 取整数部分
x=x-y; //取小数部分
result=(long long)pow(10.0,x);
printf("%d\n",result);
}
return 0;
}
