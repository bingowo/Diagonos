#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int list[10][3];
int cmp(const void*a, const void*b);
main()
{
	int n,m,a,b,c;
	start:n=0,m=0;
	scanf("%d %d",&n,&m);
	if (m==0&&n==0)
		return 0;
	else
	{
		int list[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};//积分、胜场数、负场数
		int team_table[10]={'\0'};
		for (int i=0;i<n;i++)
			team_table[i]=i+1;
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c==0)
			{
				list[a-1][0]+=1;
				list[b-1][0]+=1;
			}
			if (c==1)
			{
				list[a-1][0]+=3;
				list[b-1][0]-=1;
				list[a-1][1]+=1;
				list[b-1][2]+=1;
			}
			if (c==-1)
			{
				list[b-1][0]+=3;
				list[a-1][0]-=1;
				list[b-1][1]+=1;
				list[a-1][2]+=1;
			}
		}
		qsort(team_table,n,sizeof(team_table[0]),cmp);
		for (int i=0;i<n;i++)
			printf("%d \n",team_table[i]);
		goto start;
	}
}
int cmp(const void*a, const void*b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	if (list[x-1][0]!=list[y-1][0])//比较积分 
		return list[y-1][0]-list[x-1][0];
	else {
		if (list[x-1][1]!=list[y-1][1])//比较胜场数 
			return list[y-1][1]-list[x-1][1];
		else{
			if (list[x-1][2]!=list[y-1][2])//比较负场数 
				return list[x-1][2]-list[y-1][2];
			else
				return x-y;//比较编号 
		}
	}
}