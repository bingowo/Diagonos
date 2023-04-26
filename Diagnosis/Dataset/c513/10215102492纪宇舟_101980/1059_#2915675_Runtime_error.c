#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[1001],h[1001];
int GCD(int x,int y)
{
	if(y==0)return x;
	return GCD(y,x%y);
}
int main()
{
	memset(h,0,sizeof(h));
	int n,s;scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=1000;i++)
	for(int j=1;j<=n;j++)
	if(a[j]<i)h[i]++;
	int cnt=1;
	while(s>=h[cnt])s-=h[cnt++];
	if(s!=0)
	{
		int gcd=GCD(s,h[cnt]);
		s/=gcd;h[cnt]/=gcd;
		if(cnt!=1)printf("%d+%d/%d",cnt-1,s,h[cnt]);
		else printf("%d/%d",s,h[cnt]);
	}
	else printf("%d",cnt-1);
	return 0;
}