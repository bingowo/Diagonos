#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char id[12];
	int score;
}STU;
int cmp(const void* p1,const void* p2){
	STU *a = (STU*)p1;
	STU *b = (STU*)p2;
	if(a->score!=b->score)
		return b->score-a->score;
	for(int i=0;i<12;i++){
		if(a->id[i]>b->id[i]){
			return 1;
		}
		if(a->id[i]<b->id[i]){
			return -1;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int N,M,G;
	for(int i=0;i<T;i++){
		scanf("%d %d %d",&N,&M,&G);
		STU stu[12];
		long long int card[10]={0};
		for(int j=0;j<M;j++){
			scanf("%lld",&card[j]);
		}
		for(int j=0;j<N;j++){
			stu[j].score=0;
			scanf("%s",stu[j].id);
			int n,p;
			scanf("%d",&n);
			for(int k=1;k<=n;k++){
				scanf("%d",&p);
				stu[j].score+=card[p-1];
			}
		}
		qsort(stu,N,sizeof(STU),cmp);
		printf("case #%d:\n",i);
		int cnt=0;
		for(int k=0;k<N;k++){
			if(stu[k].score>=G)
				cnt++;
				//printf("%s %d\n",stu[k].id,stu[i].score);
		}
		printf("%d\n",cnt);
		for(int k=0;k<N;k++){
			if(stu[k].score>=G)
				printf("%s %d\n",stu[k].id,stu[k].score);
		}
	}
	return 0;
}