#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char id[12];
	int solved;    //代表学生解决的问题数 
	int total;     //代表学生获得的总分 
}STUDENT;
int cmp(const void *a, const void *b)
{
	Info * pa = (Info *)a;
	Info * pb = (Info *)b;
	if(pa->total != pb->total){
		return pb->total - pa->total;
	}else{
		return strcmp(pa->id, pb->id);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	int i;
	student* m=NULL;
	for(i=0;i<N;i++){
		int NumOfStu, NumOfQues, line;
		int cnt=0; 
		int scores[20];
		scanf("%d %d %d", &NumOfStu, &NumOfQues, &line);   //分别表示学生的人数，问题数量，及格线 
		STUDENT stu[NumOfStu];
		printf("case #%d:\n",i);
		int j;
		for(j = 0 ; j < NumOfQues; j ++){
			scanf("%d", &scores[j]);
	    }
	    for(int j = 0 ; j < NumOfStu; j ++){
			scanf("%s %d", stu[j].id, &stu[j].solved);
			stu[j].total = 0;
			for(int k = 0 ; k < stu[j].solved; k ++){
				scanf("%d", &temp);
				stu[j].total += scores[temp - 1];
			}
		}
		qsort(stu, NumOfStu, sizeof(STUDENT), cmp);
		for(; stu[cnt].total >= line; cnt ++);
		printf("case #%d:\n", i);
		printf("%d\n", cnt);
		int j;
		for(j = 0 ; j < NumOfStu; j ++){
			if(stu[j].total >= line){
				printf("%s %d\n", stu[j].id, stu[j].total);
			}
	}
}
}