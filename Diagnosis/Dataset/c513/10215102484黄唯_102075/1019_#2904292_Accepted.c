#include<stdio.h>

typedef struct{
	
	int id;
	int score;
	int win;
	int lose;
} info; 

int cmp(const void *a,const void *b){
	info *pa = (info *)a;
	info *pb = (info *)b;
	if(pa->score != pb->score){
		return pa->score > pb->score ? -1: 1;
	}else if(pa->win != pb->win){
		return pa->win > pb->win ? -1 : 1;
	}else if(pa->lose != pb->lose){
		return pa->lose > pb->lose ? 1 : -1;
	}else{
		return pa->id - pb->id;
	}
}


int main(void){
	int n,m;
	int a,b,c;
	
	scanf("%d%d",&n,&m);
	while(n || m){
		info team[n];
		for(int i = 0;i < n;i ++){
			team[i].id = i + 1;
			team[i].score = team[i].win = team[i].lose = 0;
		}
		for(int i = 0;i < m;i ++){
			scanf("%d%d%d",&a,&b,&c);
			if(c == 1){
				team[a - 1].score += 3;
				team[b - 1].score += -1;
				team[a - 1].win += 1;
				team[b - 1].lose += 1;
			}
			if(c == 0){
				team[a - 1].score += 1;
				team[b - 1].score += 1;
				
			}
			if(c == -1){
				team[b - 1].score += 3;
				team[a - 1].score += -1;
				team[a - 1].lose += 1;
				team[b - 1].win += 1;
			}
		
		}
		qsort(team,n,sizeof(info),cmp);
		for(int i = 0;i<n;i ++){
			printf("%d%c",team[i].id,i == n-1 ?'\n':' ');
		}
		scanf("%d%d",&n,&m);
	}
	return 0;	
}