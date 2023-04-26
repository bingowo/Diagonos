#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct {
	int sum,win,lose,pos;
} ARR;
int cmp(const void* a,const void* b)
{
	ARR x=*(ARR*)a;ARR y=*(ARR*)b;
	if(x.sum>y.sum)return -1;
	else if(x.sum==y.sum)
	{
		if(x.win>y.win)return -1;
		else if(x.win==y.win)
		{
			if(x.lose<y.lose)return -1;
			else if(x.lose==y.lose)
			{
				if(x.pos<y.pos)return -1;
				else return 1;
			}
			else return 1;
		}
		else return 1;
	}
	else return 1;
}
int main()
{
	int n,m;
	ARR arr[20];
	int a,b,c;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++)
		{
			arr[i].pos=i;
			arr[i].sum=arr[i].win=arr[i].lose=0;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c==1){arr[a].sum+=3;arr[a].win++;arr[b].sum-=1;arr[b].lose++;}
			else if(c==-1){arr[a].sum-=1;arr[a].lose++;arr[b].sum+=3;arr[b].win++;}
			else{arr[a].sum++;arr[b].sum++;}
		}//printf("%d\n",arr[1].sum);
		qsort(arr+1,n,sizeof(ARR),cmp);
		for(int i=1;i<=n;i++)printf("%d ",arr[i].pos);
		printf("\n");
	}
	return 0;
}