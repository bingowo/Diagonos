#include<stdio.h>
#include<stdlib.h>
struct team{
	int name;
	int score;
	int win;
	int loss;
};
int cmp(const void* p1,const void *p2){
	struct team *a=(struct team *)p1;
	struct team *b=(struct team *)p2;
	if(a->score!=b->score){
		return b->score-a->score;
	}else{
		if(a->win!=b->win){
			return b->win-a->win;
		}else{
			if(a->loss!=b->loss){
				return a->loss-b->loss;
			}else{
				return a->name-b->name;
			}
		}
	}
}
int main()
{
	int n,m;
	int a,b,c;
	struct team ball[100];
	while(scanf("%d %d",&n,&m)){
		if(m==0&&n==0)
			break;
		for(int j=0;j<n;j++){
			ball[j].name=j+1;
			ball[j].score=0;
			ball[j].win=0;
			ball[j].loss=0;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				ball[a-1].score+=3;
				ball[b-1].score-=1;
				ball[a-1].win+=1;
				ball[b-1].loss+=1;
			}
			if(c==-1){
				ball[b-1].score+=3;
				ball[a-1].score-=1;
				ball[b-1].win+=1;
				ball[a-1].loss+=1;
			}
			if(c==0){
				ball[a-1].score+=1;
				ball[b-1].score+=1;
			}
			
		}		
		qsort(ball,m,sizeof(ball[0]),cmp);
		int p;
		printf("**");
		for(p=0;p<n;p++){
			printf("%d ",ball[p].name);
		}
		printf("%d\n",ball[p].name);
	}
	
	
	return 0;
}