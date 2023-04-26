#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int ipt[11],opt[11];
void process(int x,int leth)
{
	int cnt=0;
	while(x)
	{
		ipt[++cnt]=x%2;x/=2;
	}
	for(int i=1;i<=leth-cnt;i++)printf("0");
	for(int i=cnt;i>0;i--)printf("%d",ipt[i]);
}
int main()
{
	char chr[505];
	scanf("%s",chr);
	int cnt=1,sum=0;
	int n=strlen(chr);
	printf("0001");
	process(n,10);
	for(int i=0;i<n;i++,cnt++)
	{
		sum=sum*10+(chr[i]-'0');
		if(i==n-1&&cnt!=3)
		{
			if(cnt==1)process(sum,4);//4
			else process(sum,7);//7
			break;
		}
		if(cnt==3)
		{
			process(sum,10);
			cnt=0;sum=0;
		}
		//printf("%d\n",sum);
	}
	return 0;
}