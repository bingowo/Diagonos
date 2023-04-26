#include<stdio.h>
using namespace std;
char s[61];
int value[128];
int main()
{
	int t;
	int num;
	int jz;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		num=0;
		jz=1;
		for(int j=0;j<128;j++) value[j]=-1;
		scanf("%s",&s);
		char *p=s;
		value[*p]=1;
		//printf("%d",value[*p]);
		while(*++p)
		{
			if(value[*p]==-1)
			{
				value[*p]=num;
				if(num==0) num=num+2;
				else num=num+1;
				jz+=1;
			}
			//printf("%d",value[*p]);
		}
		if(jz==1) jz=2;
		//printf("%d\n",jz);
		long long ans =0;
		p=s;
		while(*p) ans=ans*jz+value[*p++];
		printf("%lld\n",ans);
	}
} 