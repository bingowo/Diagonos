#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int no;
	int score;
	int win;
	int loss;
} table;
int n,m,sp=-1;
char ans[500];
int cmp(const void*a, const void*b){
	table *x=(table*)a,*y=(table*)b;
	int ans=0;
	if(x->score!=y->score)ans=x->score>y->score?-1:1;
	else if(x->win!=y->win)ans=x->win>y->win?-1:1;
	else if(x->loss!=y->loss)ans=x->loss>y->loss?1:-1;
	else ans=x->no<y->no?-1:1;
	return ans;
}
int main(){
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		table team[n];
		for(int i=0;i<n+1;i++){
			team[i].no=i;
			team[i].score=0;
			team[i].win=0;
			team[i].loss=0;
		}
		for(int i=0;i<m;i++){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			if(c==1){
				team[a-1].score+=3;team[a-1].win+=1;
				team[b-1].score-=1;team[b-1].loss+=1;
			}
			else if(c==-1){
				team[b-1].score+=3;team[b-1].win+=1;
				team[a-1].score-=1;team[a-1].loss+=1;
			}
			else{
				team[a-1].score+=1;team[b-1].score+=1;
			}
		}
		qsort(team,n,sizeof(table),cmp);
		
		for(int i=0;i<n-1;i++){
			ans[++sp]=team[i].no+1+'0';
			ans[++sp]=' ';
		}
			
		ans[++sp]=team[n-1].no+1+'0';
		ans[++sp]='\n';
	}
	
	ans[++sp]=0;
	printf("%s",ans);
	return 0;
}