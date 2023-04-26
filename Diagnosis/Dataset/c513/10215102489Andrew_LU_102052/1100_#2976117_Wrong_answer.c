#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long ABS(long long x)
{
	if(x<0)return -x;return x;
}
int main()
{
	char s[105];
	int tab[505][505];
	memset(tab,0,sizeof(tab));tab[200][200]=1;
	scanf("%s",s);
	int n=strlen(s);
	long long x=200,y=200,sumx=0,sumy=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')y+=1;
		else if(s[i]=='D')y-=1;
		else if(s[i]=='L')x-=1;
		else x+=1;
		tab[x][y]=1;
	}
	sumx=x-200;sumy=y-200;
	if(sumx!=0||sumy!=0)
	{
		long long posx=sumx,posy=sumy;
		//while(ABS(posx)<=200&&ABS(posy)<=200)
		{
				for(int i=0;i<n;i++)
			{
				if(s[i]=='U')posy+=1;
				else if(s[i]=='D')posy-=1;
				else if(s[i]=='L')posx-=1;
				else posx+=1;
				tab[posx+200][posy+200]=1;
			}
		}
	}
	//printf("%d\n",tab[120][200]);
	//printf("%lld %lld\n",sumx,sumy);
	int q;scanf("%d",&q);
	while(q--)
	{
		int ans=0;
		scanf("%lld%lld",&x,&y);
		if(ABS(x)<=200&&ABS(y)<=200)
		{
			if(tab[x+200][y+200])ans=1;
		}
		if(sumx==0&&sumy==0)
		{
			if(ABS(x)<=200&&ABS(y)<=200&&tab[x+200][y+200])ans=1;
		}
		else if(sumx==0)
		{
			if(sumy*y>=0)
			y=y-sumy*(y/sumy);
			//else y=y+sumy*(y/sumy);
			if(ABS(x)<=200&&ABS(y)<=200&&tab[x+200][y+200])ans=1;
		}
		else if(sumy==0)//测试点8 
		{
			if(sumx*x>=0)
			x=x-sumx*(x/sumx);
			//else x=x+sumx*(x/sumx);
			if(ABS(x)<=200&&ABS(y)<=200&&tab[x+200][y+200])ans=1;
		}
		else 
		{
			long long k1=ABS(x/sumx),k2=ABS(y/sumy),nx,ny;
			nx=x-sumx*k1;ny=y-sumy*k1;
			if(ABS(nx)<=200&&ABS(ny)<=200&&tab[nx+200][ny+200])ans=1;
			nx=x-sumx*k2;ny=y-sumy*k2;
			if(ABS(nx)<=200&&ABS(ny)<=200&&tab[nx+200][ny+200])ans=1;
		}
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}