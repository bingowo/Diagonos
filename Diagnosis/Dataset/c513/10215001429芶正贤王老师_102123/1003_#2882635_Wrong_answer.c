/*1003.按数据中1的位数排序*/

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b);

struct data{
	long long int a;              /*整数                            */
	int number;                   /*64位二进制补码表示中1的位数     */ 
};

int main()
{
	 
	int T;                     /*问题数                           */       
	int i,index;
	
	scanf("%d",&T);
	getchar();
	
	
	/*问题数循环开始  */
for(index = 0;index < T;index++)
{
	struct data p[10000];
	int N;                     /*排序数                           */ 
	scanf("%d",&N);
	getchar();
	/*排序数循环开始*/ 
	for(i = 0;i < N;i++)
	{
		scanf("lld",&p[i].a);   /*一个问题中所有待排序的数        */
		int d = 1,t;
		p[i].number = 0;        /*初始化1的位数为0                */ 
		for(t = 0;t < 64;t++)
		{
			if(p[i].a & d)
			p[i].number ++;     /* 1的位数增加                    */ 
			d = d<<1;
		}
	}
	getchar();
	printf("case #%d\n",index);
	qsort(p,N,sizeof(p[0]),cmp);
	for(i = 0;i <= N-1;i++)
	printf("%lld",p[i].a);
	 printf("%lld\n",p[i].a);
	
	
}
	/*问题数循环结束  */
}

int cmp(const void *a,const void *b)
{
	struct data d1,d2;
	d1 = *((struct data *)a);
	d2 = *((struct data *)b);
	if(d2.number != d1.number)
	return d2.number - d1.number ;
	else
	{
		if (d1.a > d2.a )
		return 1;
		else
		return -1;
	}
}
