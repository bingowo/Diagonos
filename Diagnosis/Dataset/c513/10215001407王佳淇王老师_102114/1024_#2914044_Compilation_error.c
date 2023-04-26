#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char num[12];//学号 
	int S;//答对数 
	int c[11];//对的号 
	int sum=0; 
}STU;
int cmp(const void*a,const void*b){
	int s1=((STU*)a)->sum,s2=((STU*)b)->sum;
	int ta,tb;
	if(s1==s2) {
		return strcmp(((STU*)a)->num, ((STU*)b)->num);
	}
	else return (s2-s1)>0?1:-1;
}
int main(){
	int T,N,M,G;
	int score[100];
	STU stu[502];
	STU pass[502]; 
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{//题目 
		scanf("%d %d %d\n",&N,&M,&G);//人数 题数 线 
		for(int j=0;j<M;j++) scanf("%d",&score[j]);//分值 
		for(int v=0;v<N;v++) {
			
		scanf("%s %d",&stu[v].num,&stu[v].S);//输号 对数 
		for(int l=0;l<stu[v].S;l++) {scanf("%d ",&stu[v].c[l]);//输对题号
		stu[v].sum+=score[stu[v].c[l]-1];}//算总分 
	}
	int q=0;
      for(int p=0;p<N;p++){
      	if(stu[p].sum>=G) pass[q++]=stu[p];
	  }
	qsort(pass,q,sizeof(STU),cmp);//比较 
	printf("case #%d:\n",i);//输出 
	printf("%d\n",q);
	for(int h=0;h<q;h++) 
	printf("%s %d\n",pass[h].num,pass[h].sum);
	} 
	return 0;
}