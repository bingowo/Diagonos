#include <stdio.h>
#include <stdlib.h>
/*该题的思路是用结构体储存学生信息，把N位同学的信息放到结构体类型的数组中，
进行qsort排序,cmp可以通过结构体指针访问学号与成绩，进行比较； 
1.->的运算级别高于==,<,>
2.q[i].num是一个空间，要用&，即&q[i].num
*/ 
typedef struct{
	char str[12]; //学号 
	int num;     //解出来的题数 
	int score;  //总分 
} Inf; 


int cmp(const void *a,const void *b)
{
	Inf* pa=(Inf*)a;
	Inf* pb=(Inf*)b;
	if(pa->score == pb->score )
	{
		for(int i=0; i<11; i++)
		{
		if(pa->str[i]==pb->str[i])  continue;
		else if (  pa->str[i] > pb->str[i]  )  return 1;
	    else return -1;
		}
	}
	return (pa->score)<(pb->score)?1:-1;
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
		
		/*******************输入每道题对应的分值********************/ 
		for(int i=0; i<M; i++)//输入每道题对应的分值，分值对应表 
		{
			scanf("%d",&p[i]);
		}
		
		/*******************输入学生信息：学号，答对题数，得分********************/
		int temp,numbers=0;
		for(int i=0; i<N; i++)
		{
			int score_=0;//总分数 
			scanf("%s", &q[i].str );//输入学号 
			scanf("%d", &q[i].num );// 答对题数
			for(int k=0; k<q[i].num; k++)// 答对的题号，利用分值对应表 ，换算 
			{
				scanf("%d",&temp);
				score_+=p[temp-1];
			}
			(q[i].score)=score_;
			if(score_>=G)  numbers++;//记录过分数线的人数 
		}
		
		/*******************************排序，输出********************************/ 
		qsort(q,N,sizeof(Inf),cmp);
		printf("case #%d:\n",j);
		printf("%d\n",numbers);
		for(int i=0; i<numbers; i++)//输出过分数线的人数 
		{
		printf("%s %d",q[i].str,q[i].score);
		printf("\n");	
		}
	}
}