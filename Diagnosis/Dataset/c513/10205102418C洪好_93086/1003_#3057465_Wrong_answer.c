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
int count(long long x)
{
	int c=0,i;
	long long a=1;
	for(i=0;i<64;i++)
	{
		if(x&a!=0)  c++;  //直接二进制与运算
		//if(x&a)  c++;
		//该位为1时与的结果不为0 
		a=a<<1; 
	}
	return c;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		mem m[10000];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&m[j].data);
			m[j].num=count(m[j].data);
		}
		qsort(m,n,sizeof(m[0]),cmp);	
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)
			printf("%lld ",m[j].data);
		printf("\n");	
	}	
	return 0;
} 