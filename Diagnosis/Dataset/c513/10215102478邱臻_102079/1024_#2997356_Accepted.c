#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct grade{
	char number[11];
	int total_score;
};
int cmp(const void*a,const void*b){
	struct grade p1,p2;
	p1=*(struct grade*)a;p2=*(struct grade*)b;
	if(p1.total_score!=p2.total_score)return p1.total_score>p2.total_score?-1:1;
    else return strcmp(p1.number,p2.number);	
}
int main() {
	int t,i,j,k,z,n,m,g,count,x,total;
	struct grade student[501];
	int score[11];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		count=0;
		scanf("%d%d%d",&n,&m,&g);
		for(j=0;j<11;j++)score[j]=0;
		for(j=0;j<m;j++)scanf("%d",&score[j]);  //储存每道题的分值
		for(k=0;k<n;k++){
			student[k].total_score=0;
			scanf("%s%d",student[k].number,&total);
			for(z=0;z<total;z++){
				scanf("%d",&x);
				student[k].total_score+=score[x-1];  //实时记录总分 
			}
			if(student[k].total_score>=g)count++;
		}  //记录每个学生情况
		qsort(student,n,sizeof(student[0]),cmp);
		printf("case #%d:\n%d\n",i,count);
		if(count!=0){
		    for(j=0;j<count;j++){
			    printf("%s %d\n",student[j].number,student[j].total_score);
		    } 
	    }
	}
	return 0;
}