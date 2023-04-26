#include<stdio.h>
typedef struct mem
{
	long long data;
	int num;
}mem;

int cmp(const void* a,const void*b)
{
	struct mem d1,d2; //结构体排序必须先转换类型 
    d1=*(( struct mem *) a );
    d2=*(( struct mem *) b );
	if(d1.num==d2.num)
		return d1.data-d2.data;
	else
		return d2.num-d1.num;
}

int count(int n)
{
	int len=1,x=n,flag=0,count=0,i;
	if(x>=0)
	{
		while(x/2!=0)
		{
			x/=2;
			len++;
		}
		for(i=0;i<len;i++)
		{
			if(n%2==1)	count++;
			n/=2;
		}
	}
	else 
	{
		x=0-(x+1);
		n=0-(n+1);
		flag=1;
		if(x/2!=0)
		{
			x/=2;
			len++;
		}
		for(i=0;i<len;i++)
		{
			if(n%2==1)	count++;
			n/=2;
		}
		count=64-count;
	}	 
	return count;
}

int main()
{
	int t;
	scanf("%d",&t);
	int i,j;
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		struct mem a[10000];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j].data);
			a[j].num=count(a[j].data);
		}	
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
			printf("ll%d ",a[j].data);
		printf("\n");
	}
} 