#include<stdio.h>
#include<stdlib.h>

struct team{
	int num;
	int score;
	int win;
	int lose;
};

int cmp(const void* a, const void* b){
	struct team a1=*(struct team*)a;
	struct team a2=*(struct team*)b;
	if(a1.score!=a2.score) return (a1.score-a2.score)<0;
	else if(a1.win!=a2.win) return (a1.win-a2.win)<0;
	else if(a1.lose!=a2.lose) return (a1.lose-a2.lose)>0;
	else return (a1.num-a2.num)>0;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	while(n!=0 || m!=0){
		int i,j;
		struct team p[n];
		for(i=1;i<=n;i++){
			p[i].num=i;
			p[i].score=0;
			p[i].lose=0;
			p[i].win=0;
		}
		int a,b,c;
		for(j=0;j<m;j++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				p[a].score+=3;
				p[b].score-=1;
				p[a].win+=1;
				p[b].lose+=1;
			}
			else if(c==-1){
				p[a].lose+=1;
				p[a].score-=1;
				p[b].score+=3;
				p[b].win+=1;
			}
			else{
				p[a].score+=1;
				p[b].score+=1;
			}
		}
		qsort(p,n+1,sizeof(p[0]),cmp);
		for(i=1;i<=n;i++){
			printf("%d%c",p[i].num,(i!=n)?' ':'\n');
		}
		scanf("%d %d",&n,&m);
	} 
}