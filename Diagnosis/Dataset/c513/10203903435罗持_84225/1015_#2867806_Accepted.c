#include <stdio.h>
int T;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
				61,67,71,73,79,83,89,97,101};
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		int a[30] = {0},b[30] = {0};
		int idxa = 0, idxb = 0;
		int num;
		while(~scanf("%d",&num))
		{
			a[idxa] = num;
			idxa++;
			char c = getchar();
			if(c == ' ') break;
		}
		while(~scanf("%d",&num))
		{
			b[idxb] = num;
			idxb++;
			char c = getchar();
			if(c == '\n') break;
		}
		int anum[30] = {0},bnum[30] = {0};
		int id = 0;
		for(int i=idxa-1;i>=0;i--) 
		{
			anum[id] = a[i];
			id++;
		}
		id = 0;
		for(int i=idxb-1;i>=0;i--)
		{
			bnum[id] = b[i];
			id++;
		}
		int res[50] = {0};
		for(int i=0;i<26;i++) res[i] = anum[i]+bnum[i];
		for(int i=0;i<26;i++)
		{
			res[i+1] += res[i]/prime[i];
			res[i] %= prime[i];
		}
		printf("case #%d:\n",kase);
		int st = 40;
		while(res[st]==0) st--;
		for(int i=st;i>0;i--) printf("%d,",res[i]);
		printf("%d\n",res[0]);
	}
	return 0;
}