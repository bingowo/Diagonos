#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char name[12];
	int sum;
}STUDENT;
STUDENT list[500];

int cmp(const void* a,const void* b)
{
	STUDENT x,y;
	x=*(STUDENT*)a;
	y=*(STUDENT*)b;
	if (x.sum>y.sum){
		return -1;
	}
	else if (x.sum<y.sum){
		return 1;
	}
	else {
		return strcmp(y.name,x.name);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,j,k;
	int N,M,G,num,que;
	int score[11];
	for (i=0;i<T;i++){
		int cnt=0;
		printf("case #%d:\n",i);
		scanf("%d %d %d",&N,&M,&G);
		for (j=1;j<=M;j++){
			scanf("%d",&score[j]);
		}
		for (j=0;j<N;j++){
			scanf("%s",list[j].name);
			list[j].sum=0;
			scanf("%d",&num);
			for (k=0;k<num;k++){
				scanf("%d",&que);
				list[j].sum+=score[que];
			}
			if (list[j].sum>=G){
				cnt++;
			}
		}
		qsort(list,N,sizeof(STUDENT),cmp);
		printf("%d\n",cnt);
		for (j=0;j<cnt;j++){
			printf("%s %d\n",list[j].name,list[j].sum);
		}
	}
	return 0;
}
