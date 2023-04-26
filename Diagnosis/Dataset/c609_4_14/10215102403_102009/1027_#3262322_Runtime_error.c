#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char number[12];
	int done[10];
	int mark;
};

struct student s[500];

int cmp(const void* a, const void* b){
	struct student a1,a2;
	a1=*(struct student*)a;
	a2=*(struct student*)b;
	if(a1.mark!=a2.mark) return (a1.mark-a2.mark)<0;
	else return strcmp(a1.number,a2.number)>0;
}

int main(){
	int t,i;
	scanf("%d",&t); 
	for(i=0;i<t;i++){
		int n,m,g,j,k,right;
		scanf("%d %d %d",&n,&m,&g);
		int score[m];
		for(j=0;j<m;j++) scanf("%d",&score[j]);
		for(j=0;j<n;j++){
			scanf("%s",&s[j].number);
			scanf("%d",&right);
			for(k=0;k<right;k++) scanf("%d",&s[j].done[k]);
		}
		k=0;
		for(j=0;j<n;j++){
			s[j].mark=0;
			while(s[j].done[k]!=0){
				s[j].mark += score[s[j].done[k]-1];
				k++;
			}
			k=0;
		}
		qsort(s,n,sizeof(s),cmp);
		j=0; int higher=0;
		while(s[j++].mark>=g) higher++;
		printf("case #%d:\n%d\n",i,higher);
		for(k=0;k<higher;k++) printf("%s %d\n",s[k].number,s[k].mark);
	}
	return 0;
} 