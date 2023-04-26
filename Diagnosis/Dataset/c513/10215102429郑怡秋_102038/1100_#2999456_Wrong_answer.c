#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int walk(int a,int xi,int x)
{
	if(x>0&&a>=xi&&(a-xi)%x==0) return (a-xi)/x;
	else if(x<0&&a<=xi&&(a-xi)%x==0) return (a-xi)/x;
	else if(x==0&&a==xi) return -2;
	else return -1;
}
int main()
{
	char ord[310];
	scanf("%s",ord);
	int l=strlen(ord);
	int t;
	scanf("%d",&t);
	long long x=0,y=0;
	long long a,b;
	for(int i=0;i<t;i++)
	{
		x=0;y=0;
		scanf("%lld%lld",&a,&b);
		int k;
		long long an[110][3];
		an[0][0]=0;
		for(k=1;k<=l;k++)
		{
			if(x==a&&y==b) break;
			if(ord[k-1]=='U') y++;
			else if(ord[k-1]=='D') y--;
			else if(ord[k-1]=='L') x--;
			else if(ord[k-1]=='R') x++;
			an[k][0]=x;an[k][1]=y;
		}//printf("%d %d\n",x,y);
		if(k<=l) printf("Yes\n");
		else
		{
			int ans=0;
			for(int i=0;i<=l;i++)
			{
				ans=0;
				int cra=walk(a,an[i][0],x);
				int crb=walk(b,an[i][1],y);
				if(cra==-1||crb==-1) ans=0;
				else if(cra==-2||crb==-2) ans=1;
				else if(cra==crb) ans=1;
				else ans=0;
				if(ans) break;
			}
			if(ans) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}