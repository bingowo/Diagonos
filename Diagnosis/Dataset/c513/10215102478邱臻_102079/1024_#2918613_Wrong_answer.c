#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long stoll(char** number){
	long long int i=0,result=0;;
	char c;
	while(number[i]!='\0'){
		result+=result*10+(number[i]-'0');
		i++;
	}
	return result;
}
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=*(long long int(*)[2])a;p2=*(long long int(*)[2])b;
	if(*p1!=*p2)return *p2-*p1;
	else return *(p1+1)-*(p2+1);
}
int main() {
	char number[501][12];
	long long int t,student,i,j,n,m,g,x,z,k,s,s1;
	long long int score[11],total[501][3]={0};
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		for(j=0;j<11;j++)score[j]=0;
		for(j=0;j<501;j++){
			for(z=0;z<3;z++)total[j][z]=0;
		}
		student=0;
		scanf("%lld %lld %lld",&n,&m,&g);
		for(j=0;j<m;j++){
			scanf("%lld",&score[j]);  //每题的分值 
		}
		for(k=0;k<n;k++){
			scanf("%s",number[k]);  //学生的学号 
			scanf("%lld",&s);  //学生总共回答的题数 
			for(z=0;z<s;z++){
				scanf("%lld",&s1);  //回答对的题号
				total[k][0]+=score[s1-1];  //每个学生总得分 
			}
			total[k][1]=stoll(number[k]);
			total[k][2]=k;
			if(total[k][0]>=g)student++;  //分数线之上的人数 
		}
		qsort(total,n,sizeof(total[0]),cmp);
		printf("case #%lld:\n%lld\n",i,student);
		for(x=0;x<student;x++){
			printf("%s %lld\n",number[total[x][2]],total[x][0]);
		}
	}
	return 0;
}
