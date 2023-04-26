#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct grade{
	int total;
	char* number;
} gra[501];   //存储学号和总分 
cmp(const void* a,const void* b){
	struct grade p1,p2;
	p1=*(struct grade *)a;p2=*(struct grade *)b;
	if(p1.total!=p2.total){
		if(p1.total>p2.total)return -1;
		else return 1;
	}
	else return strcmp(p1.number,p2.number);
}
int main(){
	int t,n,m,g,i,j,x,z,k,s,s1,student; 
	int score[11];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		student=0;
		for(j=0;j<11;j++)score[j]=0;
		for(k=0;k<501;k++){
			gra[k].total=0;
			gra[k].number="\0";
		}
		scanf("%d %d %d",&n,&m,&g);
		for(j=0;j<m;j++){
			scanf("%d",&score[j]);
		}   //记录每题的分值 
		for(k=0;k<n;k++){
			scanf("%s",gra[k].number);  //记录学生的学号 
			scanf("%d",&s);  //一共回答的题数
			for(k=0;k<s;k++){
				scanf("%d",&s1);
				gra[k].total+=score[s1-1];
			}   //记录学生的总分
			if(gra[k].total>=g)student++;  //超过分数线的人数 
		}  //记录每个学生的情况 
		qsort(gra,n,sizeof(gra[0]),cmp);
		printf("case #%d:\n%d\n",i,student);
		for(z=0;z<student;z++){
			printf("%s %d\n",gra[z].number,gra[z].total);
		}
	}
	return 0;
}