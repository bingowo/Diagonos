#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n,w[105],sum,sig,book[100005],tap[15]; 
int cmp(const void *e1,const void *e2)
{
	return *(int*)e1-*(int*)e2;
}
void biaoji(int l,int r)
{
	book[r-l]=1;
//	printf("%d ",r-l);
	for(int i=1;i<=n;i++)
	{
		if(tap[i]==0&&(r-2*w[i]-l)>0)
		{
			tap[i]=1;
			biaoji(l+w[i],r-w[i]);
			tap[i]=0;
		}
	}
}
void biaoji0(int l,int r)
{
	biaoji(l,r);
	for(int i=1;i<=n;i++)
	{
		if(tap[i]==0)
		{
			tap[i]=1;
			biaoji0(0,r-w[i]);
			tap[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		book[w[i]]=1;
		sum+=w[i];
	}
	qsort(w+1,n,sizeof(w[0]),cmp);
	biaoji(0,sum);
	for(int i=1;i<=n;i++)
	{
		tap[i]=1;
		biaoji0(0,sum-w[i]);
		tap[i]=0;
	}
	for(int i=1;i<=sum;i++)
	{
		if(book[i]==1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}