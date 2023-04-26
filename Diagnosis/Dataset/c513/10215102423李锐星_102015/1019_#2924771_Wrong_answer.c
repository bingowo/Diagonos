#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int name;
	int score;
	int win;
	int lose;
}LIST;

int cmp(const void* a,const void* b){
	LIST x,y;
	x=*(LIST*)a;
	y=*(LIST*)b;
	if (x.score>y.score){
		return -1;
	}
	else if (x.score<y.score){
		return 1;
	}
	else {
		if(x.win>y.win){
			return -1;
		}
		else if (x.win<y.win) {
			return 1;
		}
		else {
			if(x.lose<y.lose){
				return -1;
			}
			else if (x.lose>y.lose){
				return 1;
			}
			else {
				if (x.name<y.name){
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
}
int main()
{
	int n,m;
	int a,b,c;
	int i;
	LIST excel[11];
	while(scanf("%d %d",&n,&m)!=EOF){
		if (m==0&&n==0){
			break;
		}
		for (i=1;i<=n;i++){
			excel[i].name=i;
			excel[i].score=0;
			excel[i].win=0;
			excel[i].lose=0;
		}
		for (i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			if (c==1){
				excel[a].score+=3;
				excel[a].win+=1;
				excel[b].score-=1;
				excel[b].lose+=1;
			}
			else if (c==-1){
				excel[b].score+=3;
				excel[b].win+=1;
				excel[a].score-=1;
				excel[a].lose+=1;
			}
			else {
				excel[a].score+=1;
				excel[b].score+=1;
			}
		}
		qsort(excel,n,sizeof(LIST),cmp);
		for (i=1;i<n;i++){
			printf("%d ",excel[i].name);
		}
		printf("%d\n",excel[i].name);
	}
	return 0;
}