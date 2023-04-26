#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char num[12];int score;
}STUDENT;

int cmp(const void* a,const void* b)
{
	STUDENT m = *(STUDENT*)a, n = *(STUDENT*)b;
	if(m.score == n.score)
		return strcmp(m.num,n.num);
	else
		return n.score - m.score;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		int N,M,G,count=0,S;
		scanf("%d %d %d",&N,&M,&G);
		
		STUDENT* stu = (STUDENT*)calloc(N,sizeof(STUDENT));
		int *m = (int*)calloc(M,sizeof(int));
		for(int i=0;i<M;i++)
			scanf("%d",m+i);
		for(int i=0;i<N;i++)
		{
			int x,sum=0;
			char s[12];
//			s[11]='\0',s[0]=getchar();
//			for(int i=0;i<=10;i++)
//				s[i]=getchar();
			
			scanf("%s %d",s,&S);
			for(int i=0;i<S;i++)
			{
				scanf("%d",&x);
				sum = sum + m[x-1];
			}
			if(sum >= G)
			{
				stu[count].score = sum;
				strcpy(stu[count].num,s);
			//	printf("storage: %s\n",stu[count].num);
				count++;
			}
		}
		qsort(stu,count,sizeof(STUDENT),cmp);
		
		printf("case #%d:\n%d\n",i,count);
		for(int i=0;i<count;i++)
		{
			printf("%s %d\n",stu[i].num,stu[i].score);
		}
		free(stu);
		free(m);
	}
	return 0;
}