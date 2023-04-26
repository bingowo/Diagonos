#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void *a,const void *b)
{
	TEAM a1=*(TEAM *)a;
	TEAM b1=*(TEAM *)b;
	if((a1.point)!=(b1.point))return (a1.point>b1.point)?-1:1;
	else if(a1.point==b1.point)
	{
		if(a1.win!=b1.win)return ((a1.win>b1.win)?-1:1);
		else if(a1.lose!=b1.lose)return ((a1.lose<b1.lose)?-1:1);
		else if((a1.num)!=(b1.num))return ((a1.num)<(b1.num)?-1:1);
	}
}
typedef struct team{
		int num;
		int point;
		int win;
		int lose;
	}TEAM;
int main()
{
	int n,m,i;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if((n==0)&&(m==0))break;
		else
		{
			TEAM A[10];
			int a,b,c;
			for(i=0;i<n;i++)
			{
				A[i].num=i+1;
				A[i].point=0;
				A[i].win=0;
				A[i].lose=0;
			}
			for(i=0;i<m;i++)
			{
				scanf("%d %d %d",&a,&b,&c);
				if(c==1)
				{
					A[a].point+=3;A[b].point-=1;
					A[a].win+=1;A[b].lose+=1;
				}
				else if(c==-1)
				{
					A[b].point+=3;A[a].point-=1;
					A[b].win+=1;A[a].lose+=1;
				}
				else
				{
					A[a].point+=1;A[b].point+=1;
				}
			}
			qsort(A,n,sizeof(TEAM),cmp);
		}
		for(i=0;i<n-1;i++)
		{
			printf("%d ",A[i].num);
		}
		printf("%d\n",A[i].num);
	}
	
	return 0;
}
