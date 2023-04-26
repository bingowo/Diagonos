祝贺 21:33:35
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ans[1000],sp=0,dot=0,flag=1;
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
		if(flag==-1)
		{
			ans[sp-1]=ans[sp-1]==0?0:3-ans[sp-1];
		}
		a/=3;
	}while(a!=0);
}
long long sim(long long a,long long b)
{
	if(a==0 || b==0)return 1;
	if(a<b)
	{
		long long c=a;a=b;b=c;
	}
	long long c=0;
	while((c=a%b)!=0)
	{
		a=b;b=c;
	}
	return b;
}
int main()
{
	for(int i=0;i<1000;i++)ans[i]=0;
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a<0)
	{
		flag=-1;a=-a;
	}
	long long c=sim(a,b);
	itor(a/c,b/c);
	if(ans[sp]!=0)sp++;
	if(dot>=sp)
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

祝贺 21:34:24
//素数禁进制A+B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long tab[1][25]=
{{
	2,3,5,7,11,
	13,17,19,23,29,
	31,37,41,43,47,
	53,59,61,67,71,
	73,79,83,89,91
},{1}};
int main()
{
	long long t;
	scanf("%lld",&t);
	getchar();
	for(long long m=0;m<t;m++)
	{
		
		int a[30],b[30],ans[30],pa=0,pb=0,c;
		do
		{
			scanf("%d",&a[pa++]);
		}while((c=getchar()==','));
		do
		{
			scanf("%d",&b[pb++]);
		}while((c=getchar()==','));
		
		for(int i=0;i<30;i++)
			ans[i]=0;
		pa--;pb--;int p=0;
		for(;pa>=0 && pb>=0;p++,pa--,pb--)
		{
			int x=(ans[p]+a[pa]+b[pb]);
			ans[p]=x%tab[0][p];
			ans[p+1]+=x/tab[0][p];
		}
		
		for(;pa>=0;p++,pa--)
		{
			int x=ans[p]+a[pa];
			ans[p]=x%tab[0][p];
			ans[p+1]+=x/tab[0][p];
		}
		for(;pb>=0;p++,pb--)
		{
			int x=ans[p]+b[pb];
			ans[p]=x%tab[0][p];
			ans[p+1]+=x/tab[0][p];
		}
		if(ans[p]!=0)
			p++;
		
		printf("case #%d:\n",m);
		for(int i=p-1;i>0;i--)
			printf("%d,",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}

