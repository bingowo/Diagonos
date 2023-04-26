#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
typedef long long ll;
typedef unsigned long long ull;
typedef struct{ll x,y;ull Manhattan;} point;
ull myllabs(ll x)//传ll进入返回ull 
{
	ll tmp;
	if(x<0)tmp=-x;
	else tmp=x;
	return (ull)tmp;
}
ull get_manhattan (point a)
{
	return myllabs(a.x)+myllabs(a.y);
}
int cmp(const void* a,const void* b)
{
	point ax=*(point*)a,bx=*(point*)b;
	if(ax.Manhattan!=bx.Manhattan)
	{
		if(ax.Manhattan<bx.Manhattan)return 1;
		else return -1;
	}
	else
	{
		if(ax.x!=bx.x)
		{
			if(ax.x>bx.x)return 1;
			else return -1;
		}
		else
		{
			if(ax.y>bx.y)return 1;
			else return -1;
		}
	}
}
int main()
{
	int total;
	scanf("%d",&total);
	point* P=(point*)malloc(total*sizeof(point));
	for(int i=0;i<total;i++)
	{
		scanf("%lld %lld",&P[i].x,&P[i].y);
		P[i].Manhattan=get_manhattan(P[i]);
	}
	qsort(P,total,sizeof(point),cmp);
	ull distance=myllabs(P[0].x-P[1].x)+myllabs(P[0].y-P[1].y),t=1;
	printf("%llu\n",distance);
	int step=0;
	for(int i=0;i<total-1;i++)
	{
		distance=myllabs(P[i].x-P[i+1].x)+myllabs(P[i].y-P[i+1].y);
		if(distance==0)continue;
		if(distance%2) 
		{
			for(int j=1;j<=64;j++)
			{
				if(distance<=(t<<j))
				{
					step+=j;
					break;
				}
				
				if(distance>(t<<63))
				{
					step+=64;
					break;
				}
			}
			
		}
		else {break;}
	}
	printf("%d\n",step);
	free(P);
	return 0;
}