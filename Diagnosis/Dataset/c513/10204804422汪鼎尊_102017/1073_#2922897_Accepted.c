#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long gnum[20];
int debug=0;

long long goodnum(long long max,long long modifier)
{
	int i;
	if(max<10)
	{
		int t=0;
		for(i=0;i<=max;i++)if((i+modifier)%9!=0)t++;
		if(debug)printf("%lld m%lld +%d\n",max,modifier,t);
		return t;
	}
	int digits=1;
	long long tmp=max,tmp2=1;
	while(tmp>=10)
	{
		tmp/=10;
		digits++;
	}
	for(i=1;i<digits;i++)tmp2*=10;
	if(debug)printf("%lld %lld %lld %d +%lld\n",max,tmp,tmp2,digits,tmp*gnum[digits]);
	return tmp*gnum[digits]+goodnum(max-tmp2*tmp,(modifier+tmp)%9);
}

int main()
{
	int i,j;
	long long tmp=8;
	gnum[0]=0;
	gnum[1]=1;
	for(i=2;i<=19;i++)
	{
		gnum[i]=tmp;
		tmp*=9;
	}
	long long l,r;
	scanf("%lld %lld",&l,&r);
	if(debug)printf("%lld %lld\n",l,r);
	printf("%lld",(goodnum(r,0)-goodnum(l,0)+1));
	return 0;
}