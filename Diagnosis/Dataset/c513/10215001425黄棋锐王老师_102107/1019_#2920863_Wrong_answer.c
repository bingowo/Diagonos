#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct dui{
		   int num;
		   int score;
		   int win;
		   int lose;
			};	
int cmp(const void*a,const void*b){
	struct dui *aa=(struct dui*) a;
	struct dui *bb=(struct dui*) b;
	if(aa->score<bb->score) return 1;
	else if((aa->score==bb->score)&&(aa->win<bb->win)) return 1;
	else if((aa->score==bb->score)&&(aa->win==bb->win)
	&&(aa->lose>bb->lose)) return 1;
	else if((aa->score==bb->score)&&(aa->win==bb->win)
	&&(aa->lose==bb->lose)&&(aa->num>bb->num)) return 1;
}
	
int main(){
		int n,m;
		while(scanf("%d %d",&n,&m)&&(n!=0||m!=0))
		{ 
			struct dui{
		   int num;
		   int score;
		   int win;
		   int lose;
			}tea[12];
		int i,a=0,b=0,c=0;
		for(i=0;i<n;i++) tea[i].num=i+1,tea[i].score=0,tea[i].win=0,tea[i].lose=0;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			switch(c){
				case 1: tea[a-1].score+=3,tea[a-1].win+=1,
				tea[b-1].score-=1,tea[b-1].lose+=1;break;
				case -1:tea[b-1].score+=3,tea[b-1].win+=1,
				tea[a-1].score-=1,tea[a-1].lose+=1;break;
				case 0:tea[a].score+=1,tea[b].score+=1;break;
			}
		}
			qsort(tea,n,sizeof(tea[0]),cmp);
			for(i=0;i<n-1;i++) printf("%d ",tea[i].num);
			printf("%d\n",tea[i].num);
		}
		return 0;
}