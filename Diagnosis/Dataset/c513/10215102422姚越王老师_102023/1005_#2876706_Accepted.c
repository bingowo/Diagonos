#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add_and_divide(const void* a,int i)
{
	int *dec=(int*)a;
	dec[0]=i;
	int left=i,div;
	for(int j=1;j<155;j++)
	{
		div=left*10+dec[j];
		dec[j]=div/8;left=div%8;
	}
	dec[0]=0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int cnt=0;cnt<n;cnt++)
	{
		char s[1005];
		scanf("%s",s);
		int dec[155];
		for(int i=0;i<155;i++)
		{
			dec[i]=0;
		}
		int j=strlen(s);
		while(j--&&j>1)
		{
			add_and_divide(dec,s[j]-48);
		}
		int k;
		for(k=154;k>=0;k--)
		{
			if(dec[k])break;
		}
		printf("case #%d:\n",cnt);
		for(int i=0;i<=k;i++)
		{
			printf("%d",dec[i]);
			if(i==0)printf(".");
		}
		printf("\n");
	}
	return 0;
}