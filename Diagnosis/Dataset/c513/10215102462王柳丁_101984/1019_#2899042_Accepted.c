#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team{
		int num;
		int point;
		int win;
		int lose;
	}TEAM;
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

int main()
{
	int n,m,i;
	do
	{
		scanf("%d %d",&n,&m);
		TEAM A[10];
		int a,b,c;
		for(i=0;i<10;i++)
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
				A[a-1].point+=3;A[b-1].point-=1;
				A[a-1].win+=1;A[b-1].lose+=1;
			}
			else if(c==-1)
			{
				A[b-1].point+=3;A[a-1].point-=1;
				A[b-1].win+=1;A[a-1].lose+=1;
			}
			else
			{
				A[a-1].point+=1;A[b-1].point+=1;
			}
		}
			/*for(i=0;i<10;i++)
			{
				printf("%d ",A[i].num);
			}
			printf("%d\n",A[9].num);*/
		qsort(A,10,sizeof(TEAM),cmp);
		int count=0;
		for(i=0;i<10;i++)
		{
			if((count==n-1)&&(A[i].num<=n))printf("%d\n",A[i].num);
			else if(A[i].num<=n)
			{printf("%d ",A[i].num);
				count++;
			}
			
			
		}
			
	}while((n!=0)||(m!=0));
	
	return 0;
}
