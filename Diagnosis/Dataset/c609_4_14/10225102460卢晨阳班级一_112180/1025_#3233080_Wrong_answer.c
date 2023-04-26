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
	return aa->score-bb->score;
	else{
		if(aa->win!=bb->win)
		return aa->win-bb->win;
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
	while(scanf("%d %d",&m,&n)!=-1&&(n!=0&&m!=0)){
		team t[n];
		for(int i=0;i<n;i++){
			t[i].lose=0;
			t[i].win=0;
			t[i].score=0;
			t[i].number=i;
		}
		int a,b,c;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				t[a].score+=3;
				t[a].win++;
				t[b].score-=1;
				t[b].lose++;
			}else if(c==-1){
				t[b].score+=3;
				t[b].win++;
				t[a].score-=1;
				t[a].lose++;
			}else if(c==0){
				t[a].score++;
				t[b].score++;
			}
		}
		qsort(t,n,sizeof(t[0]),cmp);
		for(int i=0;i<n;i++)
		printf("%d ",t[i].number);
		printf("\n");
	}	
}