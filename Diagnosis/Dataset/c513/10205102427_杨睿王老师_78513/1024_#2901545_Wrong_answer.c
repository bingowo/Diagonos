#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct student{
	char num[12];
	int grade;
	char question[11];
}S;
int cmp(const void* x, const void * y){
	S xx=*(S*) x;
	S yy=*(S*) y;
	if(xx.grade==yy.grade) return strcmp(xx.num,yy.num);
	else return yy.grade-xx.grade;
}
int main(){
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		int n,m,g;
		scanf("%d %d %d",&n,&m,&g);
		int score[11]={0};
		for(int y=0;y<m;y++){
			scanf("%d",&score[y]);
			//printf("%d/",score[y]);
		}
		S s[501];
		
		for(int y=0;y<n;y++){
			//printf("test\n");
			char ch=getchar();
			int l=0;
			/*while(ch=getchar()!=' '){
				s[y].num[l]=ch-;
				l++;
			}*/
			for(int r=0;r<12;r++)
			{
				scanf("%c",&s[y].num[r]);
			}
			/*for(int r=0;r<12;r++)
			{
				printf("%c",s[y].num[r]);
			}				
			printf("\n");*/
			//getchar();
			int number;
			int total=0;
			scanf("%d",&number);
			for(int r=0;r<number;r++){
				scanf("%d",&s[y].question[r]);
				total+=score[s[y].question[r]-1];
			}
			s[y].grade=total;
			//printf("%d %d\n",number,total);
		}
		qsort(s,n,sizeof(S),cmp);
		int flag=0;
		int cnt=0;
		for(int y=0;y<n;y++){
			if(s[y].grade>=g){
				flag=1;
				cnt++;
			}
		}
		printf("%d\n",cnt);		
		for(int y=0;y<n;y++){
			if(s[y].grade>=g){
				flag=1;
				for(int r=0;r<12;r++){
					printf("%c",s[y].num[r]);
				}
				printf(" ");
				printf("%d\n",s[y].grade);
			}
		}
		//if(flag==0) printf("0");
	}
}