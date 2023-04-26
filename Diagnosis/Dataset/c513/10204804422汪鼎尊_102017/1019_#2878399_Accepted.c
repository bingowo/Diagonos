#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
	int *t1=(int*)a,*t2=(int*)b;
	if(*(t1+1)!=*(t2+1))return (*(t2+1)-*(t1+1));
	if(*(t1+2)!=*(t2+2))return (*(t2+2)-*(t1+2));
	if(*(t1+3)!=*(t2+3))return (*(t1+3)-*(t2+3));
	return (*t1-*t2);
}

int main()
{
	int i,j,teams,matches,m;
	int t1,t2,stat;
	int teamdata[10][4];//0=teamnum,1=points,2=wins,3=loses
	while(~scanf("%d %d",&teams,&matches))
	{
		if(teams==0&&matches==0)return 0;
		memset(teamdata,0,4*10*sizeof(int));
		for(i=0;i<10;i++)teamdata[i][0]=i+1;
		for(m=0;m<matches;m++)
		{
			scanf("%d %d %d",&t1,&t2,&stat);
			t1--;t2--;
			if(stat==0)
			{
				
				teamdata[t1][1]++;
				teamdata[t2][1]++;
			}
			else if(stat==1)
			{
				teamdata[t1][1]+=3;
				teamdata[t2][1]--;
				teamdata[t1][2]++;
				teamdata[t2][3]++;
			}
			else if(stat==-1)
			{
				teamdata[t2][1]+=3;
				teamdata[t1][1]--;
				teamdata[t2][2]++;
				teamdata[t1][3]++;
			}
		}
		qsort(teamdata,teams,4*sizeof(int),cmp);//for(i=0;i<teams;i++)for(j=0;j<4;j++)printf("%d ",teamdata[i][j]);
		for(i=0;i<teams;i++)printf("%d%c",teamdata[i][0],i==teams-1?'\n':' ');
	}
	return 0;
}