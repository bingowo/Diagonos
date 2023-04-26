#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
unsigned long long ans=0;
void plant(long long *x,long long*y){
	long long a=*x<*y?*x:*y;
	long long b=*x>*y?*x:*y;
		ans+=a*4*(b/a);b=b%a;
	*x=a;*y=b;
}
int main()
{
	long long x,y;scanf("%lld%lld",&x,&y);
	while(x!=y && x>0 && y>0)plant(&x,&y);
	if(x==y)ans+=x*4;
	printf("%llu",ans);
	return 0;
}