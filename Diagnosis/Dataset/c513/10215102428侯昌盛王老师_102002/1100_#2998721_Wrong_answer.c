#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct point{
	int a,b;
};
int main()
{
	char s[101];
	scanf("%s",s);
	int q,i=0,x=0,y=0,len;
	len=strlen(s);
	scanf("%d",&q);
	struct point p[101];
	int t=1;
	memset(p,0,sizeof(p));
	p[0].a=0;p[0].b=0;
	for(i;i<len;i++)
	{
		if(s[i]=='U') {p[i+1].b=p[i].b+1;p[i+1].a=p[i].a;}
		else if(s[i]=='D') {p[i+1].b=p[i].b-1;p[i+1].a=p[i].a;}
		else if(s[i]=='L') {p[i+1].a=p[i].a-1;p[i+1].b=p[i].b;}
		else if(s[i]=='R') {p[i+1].a=p[i].a+1;p[i+1].b=p[i].b;}
		
	}

	struct point pn[100001];
	int j=0;
	for(j;j<q;j++)
	{
		scanf("%d %d",&pn[j].a,&pn[j].b);
	}
	
	for(j=0;j<q;j++)
	{
		
		if((pn[j].a==0)&&(pn[j].b==0)) printf("Yes\n");
		else
		{
			int k=1;
			for(k;k<=len;k++)
			{
				
				
				//printf("%d %d\n",p[2].a,p[2].b);
				if((p[k].a!=0)&&(p[k].b!=0)) 
				{
					
					if((pn[j].a/p[k].a)==(pn[j].b/p[k].b)&&(pn[j].b/p[k].b)>0)
					{
						
						printf("Yes\n");
						break;
					}
				}
				else if(p[k].a==0&&p[k].b!=0)
				{
					if((pn[j].a==0)&&(pn[j].b%p[k].b)==0&&(pn[j].b*p[k].b)>0)
					{
						printf("Yes\n");
						break;
					}
				}
				else if(p[k].b==0&&p[k].a!=0)
				{
					if((pn[j].b==0)&&(pn[j].a%p[k].a)==0&&(pn[j].a*p[k].a)>0)
					{
						printf("Yes\n");
						break;
					}
				}
				
				
			}
			if(k>len) printf("No\n");
		}
		
	}
	return 0;
}