#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ans[1000],sp=0,dot=0;
void itor(long long a,long long b)
{
	int k=0;
	while(b!=1)
	{
		k++;
		b/=3;
	}
	dot+=a==0?0:k;
	do
	{
		ans[sp++]+=a%3;
		if(ans[sp-1]+1==3)
			ans[sp]++;
		else if(ans[sp-1]+1==4)
		{
			ans[sp]++;
			ans[sp-1]=0;
		}
		a/=3;
	}while(a!=0);
}

int main()
{
	for(int i=0;i<1000;i++)ans[i]=0;
	long long a,b;
	scanf("%lld %lld",&a,&b);
	itor(a,b);
	if(ans[sp]!=0)sp++;
	if(dot==sp)
		printf("0");
	else
	{
		for(int i=sp-1;i>=dot;i--)
			printf("%d",ans[i]);
	}
	if(dot!=0)
		printf("%c",'.');
	for(int i=dot-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
}