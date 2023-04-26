#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int point;
	int num;
	int win;
	int lose;
}team;
int cmp(const void *a,const void *b){
	team *pa=(team*)a;
	team *pb=(team*)b;
	if(pa->point !=pb->point)return (pa->point>pb->point?-1:1);
	if(pa->win!=pb->win)return (pa->win>pb->win?-1:1);
	if(pa->lose!=pb->lose)return(pa->lose<pb->lose?-1:1);
	else return(pa->num<pa->num?-1:1);
}

int main(){

	int i,n,m,a,b,c;
	while(scanf("%d%d",&n,&m)==2){
		//printf("ok");
		if((n==0)&&(m==0)){
			break;
		}
		team s[12];
		for(i=0;i<m;i++){
			for(int j=1;j<=n;j++){
			s[j].num=j;
			s[j].point=0;
			s[j].win=0;
			s[j].lose=0;
			
		}
		scanf("%d%d%d",&a,&b,&c);
		if(c==1){
			s[a].point+=3;
			s[a].win++;
			s[b].point--;
			s[b].lose++;
		}
		else if(c==-1){
			s[b].point+=3;
			s[b].win++;
			s[a].point--;
			s[a].lose++;
		}
		else{
			s[a].point++;
			s[b].point++;
		}
		//printf("ok");
		
		}
		qsort(s+1,n,sizeof(team),cmp);
		for(int k=1;k<=n;k++){
			printf("%d",s[k].num);
		}
	   	printf("\n");
	}
	
	
	
	return 0;
}

