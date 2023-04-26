
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[12];
	int solved;
	int total;
}Info;

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

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int NumOfStu, NumOfQues, line;
		scanf("%d %d %d", &NumOfStu, &NumOfQues, &line);
		int scores[NumOfQues], temp, cnt = 0;
		Info stu[NumOfStu];
		for(int j = 0 ; j < NumOfQues; j ++){
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
		qsort(stu, NumOfStu, sizeof(Info), cmp);
		for(; stu[cnt].total >= line; cnt ++);
		printf("case #%d:\n", i);
		printf("%d\n", cnt);
		for(int j = 0 ; j < NumOfStu; j ++){
			if(stu[j].total >= line){
				printf("%s %d\n", stu[j].id, stu[j].total);
			}
		}
	}
	
	return 0;
}
