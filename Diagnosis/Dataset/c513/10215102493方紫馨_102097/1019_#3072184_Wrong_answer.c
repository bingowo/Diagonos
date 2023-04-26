#include<stdio.h>
#include<stdlib.h>
struct data{
	int id;
	int success;
	int loss;
	int score;
};

int cmp(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	
	if(a->score!=b->score)
		return b->score-a->score;
	if(a->success!=b->success)
		return b->success-a->success;
	if(a->loss!=b->loss)
		return a->loss-b->loss;
	return a->id-b->id;
}

int main()
{
	int n,m;
	int a,b,c;
	struct data team[10];
	while(scanf("%d%d",&n,&m)&&n!=0&&m!=0){
		for(int i=0;i<10;i++){
			team[i].id=i+1;
			team[i].success=0;
			team[i].loss=0;
			team[i].score=0;
		}
		
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(c==1){
				team[a-1].success++;
				team[b-1].loss++;
				team[a-1].score+=3;
				team[b-1].score-=1;
			}
			if(c==-1){
				team[b-1].success++;
				team[a-1].loss++;
				team[b-1].score+=3;
				team[a-1].score-=1;
			}
			if(c==0){
				team[a-1].score++;
				team[b-1].score++;
			}
		}
		qsort(team,n,sizeof(team[0]),cmp);
		//printf("\n**");
		for(int i=0;i<n-1;i++){
			printf("%d ",team[i].id);
		}
		printf("%d\n",team[n-1].id);
	}
	
	return 0;
 } 