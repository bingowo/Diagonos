#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int tab[1001][1001];
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int cmp(const void* a,const void* b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;
	else return 1;
}
int main()
{
	int a[1001];
	int T,ct=0;scanf("%d",&T);
	while(T--)
	{
		int x,y,GCD;
		memset(tab,0,sizeof(tab));
		int n,ans=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		qsort(a+1,n,sizeof(int),cmp);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				x=a[i];y=a[j];GCD=gcd(x,y);
				if(GCD>1)continue;
				if(tab[x][y]!=1)
				{
					tab[x][y]=1;++ans;
				}
			}
		}
		printf("case #%d:\n%d\n",ct++,ans);
	}
	return 0;
}