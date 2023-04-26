#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	char number[12];
	int mark=0;
};
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
		int n,m,g,j,k,right,p; 
		scanf("%d %d %d",&n,&m,&g);
		struct student s[500];
		int score[m];
		for(j=0;j<m;j++) scanf("%d",&score[j]);
		for(j=0;j<n;j++){
			scanf("%s",s[j].number);
			scanf("%d",&right);
			for(k=0;k<right;k++){
				scanf("%d",&p);
				s[j].mark+=score[p-1];
			}
		}
		qsort(s,n,sizeof(s[0]),cmp);
		j=0; int higher=0;
		while(s[j++].mark>=g&&j<n) 
			higher++;
		printf("case #%d:\n%d\n",i,higher);
		for(k=0;k<higher;k++) 
			printf("%s %d\n",s[k].number,s[k].mark);
	}
	return 0;
} 