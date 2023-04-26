#include <stdio.h>
#include <stdlib.h>
int T;
long long a[10010] = {0};
int cal(int x)
{
	int flag = 0;
	if(x<0)
	{
		x *= -1;
		x--;
		flag = 1;
	} 
	int cnt = 0;
	while(x)
	{
		if(x&1) cnt++;
		x = x>>1;
	}
	if(flag==1) cnt = 64-cnt;
	return cnt;
}
int mycmp(const void* x,const void* y)
{
	int xx = *(int*)x, yy =*(int*)y;
	if(cal(xx) == cal(yy))
	{
		if(xx > yy) return 1;
		else return -1;
	}
	else if(cal(xx) > cal(yy)) return -1;
	else return 1;
}
int main(void)
{
	scanf("%d",&T);
	int kase;
	for(kase=0;kase<T;kase++)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		qsort(a,n,sizeof(a[0]),mycmp);
		printf("case #%d:\n",kase);
		for(i=0;i<n;i++) printf("%lld ",a[i]);
		printf("\n");
	}
	return 0;
}