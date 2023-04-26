#include<stdio.h>
#include<stdlib.h>


typedef struct team{
	int score;
	int win;
	int lose;
	int number;
}team;

int cmp(const void*a,const void*b){
	team*aa=(team*)a;
	team*bb=(team*)b;
	if(aa->score!=bb->score)
	return bb->score-aa->score;
	else{
		if(aa->win!=bb->win)
		return bb->win-aa->win;
		else{
			if(aa->lose!=bb->lose)
			return aa->lose-bb->lose;
			else
			return aa->number-bb->number;
		}
	}
}

int main()
{
	int m,n;
	while(scanf("%d %d",&n,&m)!=-1){
		if(n==0&&m==0)break;
		team t[11];
		for(int i=0;i<n;i++){
			t[i].lose=0;
			t[i].win=0;
			t[i].score=0;
			t[i].number=i+1;
		}
		int a,b,c;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				t[a-1].score+=3;
				t[a-1].win++;
				t[b-1].score-=1;
				t[b-1].lose++;
			}else if(c==-1){
				t[b-1].score+=3;
				t[b-1].win++;
				t[a-1].score-=1;
				t[a-1].lose++;
			}else if(c==0){
				t[a-1].score++;
				t[b-1].score++;
			}
		}
		qsort(t,n,sizeof(t[0]),cmp);
		for(int i=0;i<n;i++)
		printf("%d ",t[i].number);
		printf("\n");
	}	
	return 0; 
}