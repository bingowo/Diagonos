#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long tab[2][25]=
{{
	2,3,5,7,11,
	13,17,19,23,29,
	31,37,41,43,47,
	53,59,61,67,71,
	73,79,83,89,91
},{1}};
int main()
{
	for(int i=1;i<25;i++)
		tab[2][i]=tab[1][i-1]+tab[2][i-1];
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