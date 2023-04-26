#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	char s[105];
	int tab[205][205];
	memset(tab,0,sizeof(tab));tab[100][100]=1;
	scanf("%s",s);
	int n=strlen(s);
	long long x=100,y=100,sumx=0,sumy=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')y+=1;
		else if(s[i]=='D')y-=1;
		else if(s[i]=='L')x-=1;
		else x+=1;
		tab[x][y]=1;
	}
	sumx=x-100;sumy=y-100;
	int q;scanf("%d",&q);
	while(q--)
	{
		int ans=0;
		scanf("%lld%lld",&x,&y);
		if(abs(x)<=100&&abs(y)<=100)
		{
			if(tab[x+100][y+100])ans=1;
		}
		if(((x>=0&&sumx>=0)||(x<0&&sumx<0))&&((y>=0&&sumy>=0)||(y<0&&sumy<0)))
		{
			int sig1=0,sig2=0;
			if(x==0&&sumx==0)sig1=1;
			if(x>0&&sumx>0&&x>=sumx&&(x%sumx)==0)sig1=1;
			if(x<0&&sumx<0&&x<=sumx&&(x%sumx)==0)sig1=1;
			if(y==0&&sumy==0)sig2=1;
			if(y>0&&sumy>0&&y>=sumy&&(y%sumy)==0)sig2=1;
			if(y<0&&sumy<0&&y<=sumy&&(y%sumy)==0)sig2=1;
			if(sig1&&sig2)ans=1;
			if(sumx!=0&&sumy!=0&&((x/sumx)!=(y/sumy)))ans=0;
		}
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}