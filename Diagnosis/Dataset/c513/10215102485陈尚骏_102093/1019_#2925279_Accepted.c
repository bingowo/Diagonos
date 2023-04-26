#include<stdio.h>
#include<stdlib.h>
struct In{
	int win;
	int lose;
	int score;
	int number;
};
int cmp(const void *a,const void *b){
	struct In *c=(struct In *)a;
	struct In *d=(struct In *)b;
	if(c->score!=d->score) return d->score-c->score;
	else{
		if(c->win!=d->win) return d->win-c->win;
		else{
			if(c->lose!=d->lose) return c->lose-d->lose;
			else return c->number-d->number;
		}
	}
}
int main(){
	int M,N,i,j,x,y,z;
	while(1){
		scanf("%d%d",&M,&N);
		if(M==0&&N==0) break;
		else{
			struct In arr[M];
			for(i=0;i<M;i++){
				arr[i].win=0;
				arr[i].lose=0;
				arr[i].number=i+1;
				arr[i].score=0;
			}
		   for(i=0;i<N;i++){
		   	scanf("%d%d%d",&x,&y,&z);
		   	if(z==1){
		   		arr[x-1].score+=3;arr[y-1].score--;
				arr[x-1].win++;arr[y-1].lose++;
			   }
			else if(z==-1){
				arr[x-1].score--;arr[y-1].score+=3;
				arr[x-1].lose++;arr[y-1].win++;
			}
			else if(z==0){
				arr[x-1].score+=1;arr[y-1].score+=1;
			}
		   }
		   qsort(arr,M,sizeof(arr[0]),cmp);
		   for(i=0;i<M;i++) printf("%d%c",arr[i].number,i==M-1?'\n':' ');
		}
	}
	return 0;
}
