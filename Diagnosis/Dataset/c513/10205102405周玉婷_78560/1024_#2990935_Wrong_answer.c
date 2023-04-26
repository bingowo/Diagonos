#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char str[12];//学号 
	int num;//解出来的题数 
	int score;//总分 
} Inf; 


int cmp(const void *a,const void *b)
{
	Inf* pa=(Inf*)a;
	Inf* pb=(Inf*)b;
	if(pa->score == pa->score )
	{
		long long int aa = atoi(pa->str);
		long long int bb = atoi(pb->str);
		return aa>bb?1:-1;
	}
	return (pa->score)<(pa->score)?1:-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	
	for(int j=0; j<t; j++)
	{
		int N,M,G;
		scanf("%d%d%d",&N,&M,&G);
		Inf* q=(Inf*)malloc(sizeof(Inf)*N);
		int* p=(int*)malloc(sizeof(int)*M);
		
		for(int i=0; i<M; i++)//输入每道题对应的分值 
		{
			scanf("%d",&p[i]);
		}
		int temp,numbers=0;
		for(int i=0; i<N; i++)
		{
			int score_=0;
			scanf("%s",&q[i].str);//输入学号 
			scanf("%d",&q[i].num );
			for(int k=0; k<q[i].num; k++)
			{
				scanf("%d",&temp);
				score_+=p[temp-1];
			}
			(q[i].score)=score_;
			if(score_>=G)  numbers++;
		}
		
		qsort(q,N,sizeof(Inf),cmp);
		printf("case #%d:\n",j);
		printf("%d\n",numbers);
		for(int i=0; i<numbers; i++)
		{
		printf("%s %d",q[i].str,q[i].score);
		printf("\n");	
		}
	}
}