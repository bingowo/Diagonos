#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int prime1[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2},prime[26];
char chr[1005];
int cnt1=0,cnt2=0,pos=0,L=0;//cnt1 ans×Ü³¤¶È cnt2 prisum³¤¶È posµÚ¼¸Î»Êý LÖÐ¼äÊý³¤¶È 
int prisum[1005],ans[1005],tran[1005],compu[1005];//compuÔÝ´æÊý×é 
void cal()
{
	int cnt3=0;
	//int jinwei=0;printf("%d\n",prime[pos]);
	memset(compu,0,sizeof(compu));
	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=cnt2;j++)
		compu[i+j-1]+=tran[i]*prisum[j];
	}
	//for(int i=cnt2;i>=1;i--)printf("%d ",compu[i]);printf("\n");
	for(int i=1;i<=L+cnt2;i++)
	{
		if(compu[i]>=10)
		{
			compu[i+1]+=compu[i]/10;
			compu[i]%=10;
		}
	}
	for(int i=L+cnt2+5;i>=1;i--)if(compu[i]!=0||i==1){cnt3=i;break;}
	//for(int i=cnt2;i>=1;i--)printf("%d ",compu[i]);printf("\n");
	if(cnt3>cnt1)cnt1=cnt3;
	for(int i=1;i<=cnt3;i++)ans[i]+=compu[i];
	for(int i=1;i<=cnt1;i++)
	{
		if(ans[i]>=10)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	for(int i=1;i<=cnt2;i++)prisum[i]*=prime[pos];
	
	for(int i=1;i<=cnt2+5;i++)
	{
		if(prisum[i]>=10)
		{
			prisum[i+1]+=prisum[i]/10;//½øÎ» 
			prisum[i]%=10;
		}
	}
	for(int i=cnt2+10;i>=1;i--)if(prisum[i]!=0){cnt2=i;break;}//´¦ÀíËØÊý³Ë»ý 
	//for(int i=1;i<=cnt2;i++)printf("%d ",prisum[i]);printf("\n");
}
void init()
{
	for(int i=1;i<=25;i++)prime[i]=prime1[25-i+1];
}
int main()
{
	init();
	int x=0;
	scanf("%s",chr);
	int leth=strlen(chr);
	prisum[++cnt2]=1;
	for(int i=leth-1;i>=-1;i--)
	{
		if(i==-1||chr[i]==',')
		{
			++pos;cal();L=0;
			continue;
		}
		tran[++L]=chr[i]-'0';
	}
	for(int i=cnt1+5;i>=1;i--)if(ans[i]!=0){cnt1=i;break;}
	for(int i=cnt1;i>=1;i--)printf("%d",ans[i]);
	//for(int i=cnt2;i>=1;i--)printf("%d ",prisum[i]);
	return 0;
}