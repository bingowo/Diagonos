#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int name;
	int score;
	int win;
	int fail;
}TEAM;
int cmp(const void*a,const void*b){
	int sa=((TEAM*)a)->score,sb=((TEAM*)b)->score;
	int wa=((TEAM*)a)->win,wb=((TEAM*)b)->win;
	int fa=((TEAM*)a)->fail,fb=((TEAM*)b)->fail;
	int na=((TEAM*)a)->name,nb=((TEAM*)b)->name;
	if(sa!=sb) return sb>sa?1:-1;
	else if(sa==sb&&wa!=wb) return wb>wa?1:-1;
	else if(sa==sb&&wa==wb&&fa!=fb) return fa>fb?1:-1;
	else if(sa==sb&&wa==wb&&fa==fb) return na>nb?1:-1;

}
int main(){
	int n,m;
	TEAM team[13];
	for(int v=1;v<=12;v++) {
	team[v].name=v;
	team[v].score=0;
	team[v].win=0;
	team[v].fail=0;
	}
	int a,b,c;
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(c==1) {
			team[a].score+=3;team[a].win++;
			team[b].score-=1;team[b].fail++;
		}
		if(c==0) {
			team[a].score++;
			team[b].score++;
		}
		if(c==-1) {
			team[a].score-=1;team[a].fail++;
			team[b].score+=3;team[b].win++;
		}
	}
	qsort(team,n,sizeof(TEAM),cmp);
	for(int j=0;j<n;j++) printf("%d ",team[j].name);
return 0;
}