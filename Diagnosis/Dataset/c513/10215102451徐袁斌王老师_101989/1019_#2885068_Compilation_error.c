#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int m=0,n=0;
	scanf("%d %d",&n,&m);
	while(m!=0&&n!=0)
	{
		int score[11],paiming[11],win[11],lose[11];
		for(int i=0;i<11;i++)
		{
			score[i]=0;win[i]=0;lose[i]=0;paiming[i]=i;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(c==1) {score[a-1]+=3;win[a-1]++;score[b-1]--;lose[b-1]++;}
			if(c==-1) {score[a-1]--;lose[a-1]++;score[b-1]+=3;win[b-1]++}
			if(c==0) {score[a-1]++;score[b-1]++;}
			for(int j=1;j<=m;j++)
			{
				paiming[j]=score[1];
				
			}
		}
		
		
		
		scanf("%d %d",&n,&m);
	}
	
	return 0;
	
	
 } 