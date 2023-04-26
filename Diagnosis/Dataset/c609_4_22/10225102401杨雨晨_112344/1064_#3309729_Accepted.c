#include <stdio.h>
long long f(long long x,long long y)
{	long long temp;
	if (x<y){temp=x;x=y;y=temp;}//调换xy 
	if (y==0){return 0;}//终止条件。小的那个已经没有了，即剩下的已经是正方形了。 
	long long v=x/y*y*4+f(y,x%y);
	return v;
}
int main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
}