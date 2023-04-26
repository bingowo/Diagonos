#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int chr1[1005],chr2[1005],cnt1=0,cnt2=0;
	long long A,B,itg,dbl;
	scanf("%lld%lld",&A,&B);
	itg=A/B;dbl=A%B;
	do{
		chr1[++cnt1]=itg%3;itg/=3;
	}while(itg);
	long long x=B/3;
	while(dbl&&B!=1)
	{
		chr2[++cnt2]=dbl/x;
		dbl=(dbl%x)*3;
	}
	for(int i=cnt1;i>=1;i--)printf("%lld ",chr1[i]);
	printf("\n");
	for(int i=1;i<=cnt2;i++)printf("%lld ",chr2[i]);
	for(int i=cnt1;i>=1;i--)chr1[i]+=1;
	for(int i=1;i<=cnt2;i++)chr2[i]+=1;
	for(int i=cnt2;i>=1;i--)
	if(chr2[i]>=3)
	{
		chr2[i]-=3;if(i!=1)chr2[i-1]+=1;
		if(i==1)chr1[1]+=1;
	}
	for(int i=1;i<=cnt1;i++)
	if(chr1[i]>=3)
	{
		chr1[i]-=3;chr1[i+1]+=1;
	}
	//for(int i=cnt1;i>=1;i--)printf("%lld ",chr1[i]);
	//printf("\n");
	//for(int i=1;i<=cnt2;i++)printf("%lld ",chr2[i]);
	int flag=0;
	for(int i=cnt1+1;i>=1;i--)
	{
		if(i<=cnt1)chr1[i]-=1;
		if(chr1[i]==0&&flag==0&&cnt1!=1)continue;flag=1;
		if(chr1[i]==-1)printf("2");
		else printf("%d",chr1[i]);
	}
	flag=0;
	if(cnt2>0&&(chr2[1]!=1||cnt2!=1))printf(".");
	for(int i=cnt2;i>=1;i--)
	if((--chr2[i])!=0&&flag==0)flag=i;
	for(int i=1;i<=cnt2;i++)
	if(chr2[i]==-1)printf("2");
	else printf("%d",chr2[i]);
	return 0;
}