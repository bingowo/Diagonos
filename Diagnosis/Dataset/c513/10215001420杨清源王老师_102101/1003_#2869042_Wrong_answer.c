#include <stdio.h>

struct data
{
	long long a;//储存原本的值
	int number;//储存补码1的位数 
};

long long cmp(const void*a , const void *b);

int main()
{
	int t , i , j;
	scanf("%d",&t);
	
	for(j = 0; j < t; j++)
	{
		int n;
		scanf("%d",&n);
		struct data p[20000]; 
		
		for(i = 0; i < n; i++)//将要排列的数输入 
		{
			scanf("%lld",&p[i].a); 
			int k;
			p[i].number = 0;//初始化number
			
			for(k = 0; k < 64; k++)//对每一个数计算number 
			{
				if(p[i].a & 1 != 0)
					p[i].number++;
				p[i].a = p[i].a >> 1;
			}
		}
		
		qsort(p,n,sizeof(p[0]),cmp);//排序 
		
		printf("case #%d:\n",j);
		for(i = 0; i < n - 1; i++)
			printf("%lld ",p[i].a);
		printf("%lld\n",p[i].a);
	}
} 


long long cmp(const void*a , const void *b)
{
	struct data d1, d2;
	d1 = *((struct data *)a);
	d2 = *((struct data *)b);
	
	if(d2.number != d1.number)
		return d2.number - d1.number;
	else
	{
		if(d1.a > d2.a)
			return 1;
		else
			return -1;
	}
}