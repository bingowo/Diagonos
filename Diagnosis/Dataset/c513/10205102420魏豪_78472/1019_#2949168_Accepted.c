#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int score;
	int win;
	int fail;
	int num;
}M;
M mumber[10];
int cmp(const void* a,const void* b){
	M*x,*y;
	x=(M*)a;
	y=(M*)b;
	if(x->score==y->score){
		if(x->win==y->win){
			if(x->fail==y->fail){
				return x->num-y->num;
			}
			else return x->fail-y->fail;
		}
		else return y->win-x->win;
	}
	else return y->score-x->score;
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		int a,b,c;
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			mumber[i].score=0;
			mumber[i].win=0;
			mumber[i].fail=0;
			mumber[i].num=i+1;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				mumber[a-1].win++;
				mumber[a-1].score+=3;
				mumber[b-1].fail++;
				mumber[b-1].score--;
			}
			else if(c==-1){
				mumber[b-1].win++;
				mumber[b-1].score+=3;
				mumber[a-1].fail++;
				mumber[a-1].score--;
			}
			else if(c==0){
				mumber[a-1].score++;
				mumber[b-1].score++;
			}
		}
		qsort(mumber,n,sizeof(mumber[0]),cmp);
		for(int j=0;j<n-1;j++) printf("%d ",mumber[j].num);
		printf("%d\n",mumber[n-1].num);
	}
	return 0;
} 