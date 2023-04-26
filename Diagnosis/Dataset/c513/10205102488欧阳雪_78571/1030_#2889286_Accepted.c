#include<stdio.h>
#include<stdlib.h>
struct data{
	long long num;
	int f;//最高位 
};
struct data d[10000];
int cmp(const void*a,const void*b)
{
	struct data da=*(struct data*)a;
	struct data db=*(struct data*)b;
	if(da.f !=db.f )
	{
		return(db.f -da.f );
	}
	else{
		//return(da.num -db.num );
		if(da.num >db.num )return 1;
		else return -1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		int t=0;
		for(int j=0;j<N;j++)
		{
			scanf("%lld",&d[j].num);
			long long temp=d[j].num ;
			if(temp<0)temp=-temp;
			while(temp>0)
			{
				if(temp>0&&temp<10)break;
				temp/=10;
			}
			d[j].f =temp;
			//printf("f:%d %lld\n",j,temp);
		}
		qsort(d,N,sizeof(d[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N-1;k++)
		{
			printf("%lld",d[k].num );
			printf(" ");
		}
		printf("%lld\n",d[N-1].num );
	}
}