#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int point;
	char num[12];
}STUDENT;
int cmp(const void* a,const void*b);
int main(){
	int T;
	scanf("%d",&T);
	int N,M,G;
	int sum;                                                    //答对总数 
	int cnt;                                                    //答对题号 
	int uptostd = 0;											//达到分数线人数 
	for(int i = 0;i < T;i++){
		scanf("%d %d %d",&N,&M,&G);
		int* test =  (int*)malloc(sizeof(int) * (M+1));
		for(int j = 0;j < M;j++)
			scanf("%d",(test+j));                                //存分值 
		STUDENT* stu = (STUDENT*)malloc(sizeof(STUDENT) * (N+1));
		for(int k = 0;k < N;k++){
			scanf("%s",(stu+k)->num);
			scanf("%d",&sum);
			(stu+k)->point = 0;
			for(int r = 0;r < sum;r++){
				scanf("%d",&cnt);
				(stu+k)->point += test[cnt-1];
			}
			if((stu+k)->point >= G)
				uptostd++;
		}
		qsort(stu,N,sizeof(STUDENT),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",uptostd);
		for(int j = 0;j < N;j++){
			if((stu+j)->point >= G)
				printf("%s %d\n",(stu+j)->num,(stu+j)->point);
		}
		free(test);
		free(stu);
		uptostd = 0;	
	}  
}
int cmp(const void* a,const void*b){
	STUDENT* aa = (STUDENT*)a;
	STUDENT* bb = (STUDENT*)b;
	if(aa->point == bb->point)
		return strcmp(aa->num,bb->num);
	else
		return bb->point - aa->point;
	
}