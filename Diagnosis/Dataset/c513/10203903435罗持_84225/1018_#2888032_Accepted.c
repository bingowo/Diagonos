#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long table[30][50] = {0};
int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
				61,67,71,73,79,83,89,97,101};
void mul(int idx,int num)
{
	for(int i=1;i<=table[idx-1][0];i++)
	{
		table[idx][i] = table[idx-1][i]*num;
	}
	for(int i=1;i<=table[idx-1][0];i++)
	{
		if(table[idx][i] >= 10)
		{
			table[idx][i+1] += table[idx][i]/10;
			table[idx][i] %= 10;
			if(i+1 > table[idx][0]) table[idx][0] = i+1;
		}
	}
	while(table[idx][table[idx][0]])
	{
		table[idx][table[idx][0]+1] += table[idx][table[idx][0]]/10;
		table[idx][table[idx][0]]%=10;
		table[idx][0]++;
	}
	table[idx][0]--;
}
void mull(int idx,int num)
{
	for(int i=1;i<=table[idx][0];i++)
		table[idx][i] *= num;
	for(int i=1;i<=table[idx][0];i++)
	{
		if(table[idx][i]>=10)
		{
			table[idx][i+1] += table[idx][i]/10;
			table[idx][i] %= 10;
			if(i+1 > table[idx][0]) table[idx][0] = i+1;
		}
	}
	while(table[idx][table[idx][0]])
	{
		table[idx][table[idx][0]+1] += table[idx][table[idx][0]]/10;
		table[idx][table[idx][0]]%=10;
		table[idx][0]++;
	}
	table[idx][0]--;
}
void add(int res[],int idx)
{
	for(int i=1;i<=table[idx][0];i++)
		res[i] = res[i]+table[idx][i];
	for(int i=1;i<=res[0];i++)
	{
		if(res[i]>=10)
		{
			res[i+1] += res[i]/10;
			res[i] %= 10;
			if(i+1 > res[0]) res[0] = i+1;
		}
	}
	while(res[res[0]])
	{
		res[res[0]+1] += res[res[0]]/10;
		res[res[0]] %= 10;
		res[0]++;
	}
	res[0]--;
}
int main(void)
{
	for(int i=1;i<27;i++) 
	{
		table[i][0] = 1;
		table[i][1] = 1;
	}
	table[0][0] = 1;
	table[0][1] = 1;
	table[1][1] = 2;
	for(int i=2;i<=25;i++)
		mul(i,prime[i]);
	int ipt[30] = {0};
	int num;
	int idx = 0;
	while(scanf("%d",&num)!=EOF)
	{
		getchar();
		idx++;
		ipt[idx] = num;
	}
	if(idx==1 && ipt[idx]==0) 
	{
		printf("0");
		return 0;
	}
	int res[100] = {0};
	int hang = 0;
	for(int i=idx;i>=1;i--)
	{
		mull(hang,ipt[i]);
		if(res[0] < table[hang][0]) res[0] = table[hang][0];
		add(res,hang);
		hang++;
	}
	for(int i=res[0];i>=1;i--) printf("%d",res[i]);
	return 0;
}