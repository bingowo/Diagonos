#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int line;
	int score;
	int win;
	int lose;
}list;

int cmp(const void* a,const void* b)
{
	list A,B;
	A=*(list*)a;
	B=*(list*)b;
	if (A.score>B.score){
		return -1;
	}
	else if (A.score<B.score){
		return 1;
	}
	else{
		if (A.win>B.win){
			return -1;
		}
		else if (A.win<B.win){
			return 1;
		}
		else{
			if (A.lose<B.lose){
				return -1;
			}
			else if (A.lose>B.lose){
				return 1;
			}
			else{
				if (A.line<B.line){
					return -1;
				}
				else if(A.line>B.line){
					return 1;
				}
			}
		}
	}
}
int main()
{
	int n,m;
	char a,b;
	list num[10];
	int i,grade;
	while(scanf("%d %d",&a,&b)!=EOF){
		for (i=0;i<n;i++){
			num[i].line=i+1;
			num[i].score=0;
			num[i].win=0;
			num[i].lose=0;
		}
		for (i=0;i<m;i++){
			scanf("%c %c",&a,&b);
			scanf("%d",&grade);
			if (grade==1){
				num[a-'0'].score+=3;
				num[a-'0'].win+=1;
				num[b-'0'].score-=1;
				num[b-'0'].lose+=1;
			}
			else if(grade==-1){
				num[a-'0'].score-=1;
				num[a-'0'].lose+=1;
				num[b-'0'].score+=3;
				num[b-'0'].win+=1;
			}
			else{
				num[a-'0'].score+=1;
				num[b-'0'].score+=1;
			}
		}
		qsort(num,n,sizeof(list),cmp);
		for (i=0;i<n-1;i++){
			printf("%d ",num[i].line);
		}
		printf("%d\n",num[i].line);
	}
	return 0;
}