#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct{
	int score,win,lose,index;
}team;
int cmp(const void*p1,const void*p2){
	team t1=*((team*)p1),t2=*((team*)p2);
	if(t1.score!=t2.score){
		return (t2.score-t1.score);
	}
	else{
		if(t1.win!=t2.win){
			return t2.win-t1.win;
		}
		else{
			if(t1.lose!=t2.lose){
				return t1.lose-t2.lose;
			}
			else{
				return t1.index-t2.index;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	int n,m;
	scanf("%d %d",&n,&m);
	while(n){
		team teaml[12];
		int i;
		for(i=1;i<=n;i++){
			teaml[i].score=0;
			teaml[i].win=0;
			teaml[i].lose=0;
			teaml[i].index=i;
		}
		for(i=0;i<m;i++){
			int a,b,judge;
			scanf("%d %d %d",&a,&b,&judge);
			if(judge==1){
				teaml[a].score+=3;
				teaml[b].score--;
				teaml[a].win++;
				teaml[b].lose++;
			}
			else if(judge==-1){
				teaml[b].score+=3;
				teaml[a].score--;
				teaml[a].lose++;
				teaml[b].win++;
			}
			else{
				teaml[a].score++;
				teaml[b].score++; 
			}
		}
		qsort(teaml+1,n,sizeof(teaml[0]),cmp);
		for(i=1;i<=n;i++){
			printf("%d ",teaml[i].index);
		}
		printf("\n");
		scanf("%d %d",&n,&m);
	}
	return 0;
}