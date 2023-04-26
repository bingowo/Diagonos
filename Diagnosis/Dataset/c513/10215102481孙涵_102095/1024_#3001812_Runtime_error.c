#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct data{
	int grades;
	char studentID[12];
}; 
int cmp (const void* a, const void* b);
int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int i;
	for (i = 0; i < T; i++){
		int N, M, G;
		scanf("%d %d %d", &N, &M, &G);
		/*
		N ---> 学生人数 
		M ---> 考试题目数 
		G ---> 分数线 
		*/
		int *quizscore = (int *)malloc(sizeof(int) * M);//每道题的分值 
		struct data *student = (struct data*)malloc(sizeof(struct data) * N);//学生列表 
		int j;
		for (j = 0; j < M; j++){
			scanf("%d",quizscore++);
		}
		for (j = 0; j < G; j++){
			char ID[12];//学生学号 
			int s;//答对问题的数目 
			scanf("%s",ID);
			int m;
			for (m = 0; m < 12; m++){
				student[j].studentID[m] = ID[m];
			}
			scanf("%d",&s);
			int *correctquiz = (int *)malloc(sizeof(int) * s);//答对问题题号的列表 
			for (m = 0; m < s; m++){
				scanf("%d",correctquiz++);
			}
			int sum = 0;
			int n;
			for (m = 0; m < s; m++){
				sum = sum + quizscore[correctquiz[m]];
			}
			student[j].grades = sum;
			int upaverage = 0;
		}
		int k,upaverage;
		upaverage = 0;
		for (k = 0; k < N; k++){
			if (student[k].grades >= G){
				upaverage++;
			}
		}
		qsort(student,N,sizeof(struct data),cmp);
		printf("case #%d\n:",i);
		printf("%d\n",upaverage);
		for (k = 0; k < N; k++){
			printf("%s %d\n",student[k].studentID,student[k].grades);
		}
	}
	return 0;
}

int cmp (const void* a, const void* b){
	struct data s1 = *((struct data*)a);
	struct data s2 = *((struct data*)b);
	if (s1.grades != s2.grades){
		return s2.grades - s1.grades;
	}else{
		return strcmp(s1.studentID,s2.studentID);
	}
} 

