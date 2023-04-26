#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct grade{
	int total;
	char number[12];
};
int cmp(const void* a,const void* b){
	struct grade p1,p2;
	p1=*(struct grade *)a;p2=*(struct grade *)b;
	if(p1.total!=p2.total)return p1.total>p2.total?-1:1;
	else return strcmp(p1.number,p2.number);
}
int main() {
	struct grade gra[500];
	int score[10];
	char str[12];
	int T,i,j,n,m,g,k,s,s1,z,student;
	scanf("%d",&T);   //问题的组数 
	for(i=0;i<T;i++){   //每一组问题 
		student=0;gra[k].total=0;
		for(j=0;j<10;j++)score[j]=0;
		scanf("%d %d %d",&n,&m,&g);
		for(j=0;j<m;j++){
			scanf("%d",&score[j]);  //每一题的分值 
		}
		for(k=0;k<n;k++){  //每一名学生的情况
		    scanf("%s %d",str,&s);   //学号和做对的题数
			strcpy(gra[k].number,str);  //存入结构体 
			for(z=0;z<s;z++){
				scanf("%d",&s1);
				gra[k].total+=score[s1-1];   //学生总分 
			} 
			if(gra[k].total>=g)student++;  //超过分数线的学生 
		} 
		qsort(gra,n,sizeof(gra[0]),cmp);
		printf("case #%d:\n%d\n",i,student);
		for(z=0;z<student;z++){
			printf("%s %d\n",gra[z].number,gra[z].total);
		}
	}
	return 0;
}