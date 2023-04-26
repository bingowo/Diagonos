#include <stdio.h>
#include <stdlib.h>
struct M
{
    char a[26];
    int b[26];
};
int main()
{
    int n,d,a[101]={0},b[101],c,y=0,ans=0;  
	char s[101];  
	struct M x[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
		scanf("%s",s);
		x[i].a[0]=s[0];
		for(int j=0;j<100;j++) x[i].b[j]=0;
		d=0;x[i].b[0]=1;
		for(int j=1;s[j]!='\0';j++)
		{
			if(s[j]==x[i].a[d]) x[i].b[d]++;
			else 
			{
				if(i!=0&&s[j]!=x[i-1].a[d+1]) y=1;
				else {d++;x[i].a[d]=s[j];x[i].b[d]++;}
			}
		}
		
	}
	if(y==1) {printf("-1");}
	else
	{
		for(int i=0;i<=d;i++)
		{
			b[i]=2100000000;
			for(int j=0;j<n;j++)
			{
				if(x[j].b[i]>a[i]) a[i]=x[j].b[i];
				if(x[j].b[i]<b[i]) b[i]=x[j].b[i];
			}
			c=(a[i]+b[i])/2;
			for(int j=0;j<n;j++)
			{
				ans+=abs(x[j].b[i]-c);
			}
		}
		printf("%d",ans);

	}
}