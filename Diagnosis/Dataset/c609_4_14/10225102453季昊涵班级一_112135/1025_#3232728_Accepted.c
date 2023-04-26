#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int a;
	int score;
	int win;
	int lose;
}team;

int cmp(const void *a,const void *b){
	team *A=(team *)a;
	team *B=(team *)b;
	if(A->score==B->score){
		if(A->win==B->win){
			if(A->lose==B->lose)
			return A->a-B->a;
			else
			return
			A->lose-B->lose;
		}
		else
		return B->win-A->win;
	}
	else
	return B->score-A->score;
}
int main(){
	int m,n;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(m==0&&n==0)
		break;
		team A[n];
		for(int i=0;i<n;i++){
			A[i].a=i+1;
			A[i].score=0;
			A[i].win=0;
			A[i].lose=0;
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				A[a-1].score=A[a-1].score+3;
				A[a-1].win++;
				A[b-1].score--;
				A[b-1].lose++;
			}
			else if(c==0){
				A[a-1].score++;
				A[b-1].score++;
			}
			else if(c==-1){
				A[b-1].score=A[b-1].score+3;
				A[b-1].win++;
				A[a-1].score--;
				A[a-1].lose++;
			}	
		}
		qsort(A,n,sizeof(A[0]),cmp);
		for(int i=0;i<n;i++)
		printf("%d ",A[i].a);
		printf("\n");
	}
	
	
	
}