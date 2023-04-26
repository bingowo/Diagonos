#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int name;
	int score;
	int win;
	int loss;
}team;
int cmp(const void* p1,const void *p2){
	team *pa = (team *)p1;
	team *pb = (team *)p2;	
	if(pa->score != pb->score)
		return pb->score - pa->score;
	if(pa->win != pb->win)
		return pb->win - pa->win ;
	if(pa->loss != pb->loss)
		return pa->loss - pb->loss;
	return pa->name - pb->name;
}
int main()
{
	int n,m;
	int a,b,c;
	team ball[1000];
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
		qsort(ball,n,sizeof(team),cmp);
		int p;
		for(p=0;p<n-1;p++){
			printf("%d ",ball[p].name);
			//printf("**%d %d %d %d\n",ball[p].name,ball[p].score,ball[p].win,ball[p].loss);
		}
		printf("%d\n",ball[p].name);
	}
	
	
	return 0;
}