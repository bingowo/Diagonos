#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu{
	char num[20];
	int score;
};
struct stu stud[1000];
int cmp(const void*a,const void*b)
{
	struct stu c=*(struct stu*)a;
	struct stu d=*(struct stu*)b;
	if(c.score!=d.score ){
		if(c.score >d.score) return -1;
		else return 1;
	}
	else return(d.num -c.num );
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N,M,G;
		int j2=0;
		scanf("%d%d%d",&N,&M,&G);
		int m[11];//记录每道题分数 
		int cnt=0;//记录上线人数 
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&m[j]);
		}
		for(int k=0;k<N;k++)
		{
			char temp[20]={0};
			int S,Score=0,j1=0;
			scanf("%s",temp);
			scanf("%d",&S);
			for(int t=0;t<S;t++)
			{
				scanf("%d",&j1);//对的题号 
				Score+=m[j1];
			}
			//printf("Score:%d\n",Score);
			if(Score>=G){
				stud[j2].score =Score;
				strcpy(stud[j2].num ,temp);
				//stud[j2].num[strlen(temp)]=0;
				//printf("学号:%d %s\n",j2,stud[j2].num );
				j2++;
				cnt++; 
			}
		}
		qsort(stud,cnt,sizeof(stud[0]),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",cnt);
		if(cnt>0){
		for(int t1=0;t1<cnt-1;t1++)
		{
			printf("%s %d\n",stud[t1].num ,stud[t1].score );
		}
		printf("%s %d\n",stud[cnt-1].num ,stud[cnt-1].score );
	    }
    }
	return 0;
}