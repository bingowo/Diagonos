#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char num[12];
	long long total;
}STU;
static int cmp(const void* a, const void* b){
	STU x = *((STU*)a);
	STU y = *((STU*)b);
	if(x.total == y.total){
		return strcmp(x.num, y.num);
	}
	if(x.total > y.total){
		return -1;
	}
	return 1;
	
}
int main(){
	int T, N, M, G, S, no;
	scanf("%d", &T);
	for(int i = 0; i<T; i++){
		int cnt = 0;//数及格
		scanf("%d %d %d", &N, &M, &G);
		int* score_table = (int*)malloc(sizeof(int) * M);
		STU* students = (STU*)malloc(sizeof(STU) * N);
		for(int j = 0; j<M; j++){//M道题的分数
			scanf("%d", &score_table[j]);
		}
		for(int j = 0; j<N; j++){//N个学生
			scanf("%s", students[j].num);
			scanf("%d", &S);
			students[j].total = 0;
			for(int k = 0; k<S; k++){
				scanf("%d", &no);
				students[j].total += score_table[no-1];
			}
			if(students[j].total >= G){
				cnt++;
			}
		}
		qsort(students, N, sizeof(STU), cmp);
		printf("case #%d:\n", i);
		printf("%d\n", cnt);
		if(cnt==0){
			continue;
		}
		for(int j = 0; j < cnt; j++){
			printf("%s %lld\n", students[j].num, students[j].total);
		}
	}
	return 0;
}