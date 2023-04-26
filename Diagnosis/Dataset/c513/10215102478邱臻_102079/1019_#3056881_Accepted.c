#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//积分 胜场数 负场数 编号
struct team{
	int number;
	int score;
	int win;
	int lose;
}; 
int cmp(const void*a,const void*b){
	struct team p1,p2;
	p1=*(struct team*)a;p2=*(struct team*)b;
	if(p1.score!=p2.score)return p1.score>p2.score?-1:1;
	else {
		if(p1.win!=p2.win)return p1.win>p2.win?-1:1;
		else {
			if(p1.lose!=p2.lose)return p1.lose>p2.lose?1:-1;
			else return p1.number<p2.number?-1:1;
		}
	}
}
int main() {
	int n,m,a,b,c,i;
	struct team s[11];
	scanf("%d%d",&n,&m);
	while(n!=0 || m!=0){
		for(i=0;i<n;i++){
			s[i].number=i+1;
			s[i].score=0;s[i].win=0;s[i].lose=0;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(c==1){
				s[a-1].score+=3;s[a-1].win+=1;
				s[b-1].score-=1;s[b-1].lose+=1;
			}
			else if(c==-1){
				s[b-1].score+=3;s[b-1].win+=1;
				s[a-1].score-=1;s[a-1].lose+=1;
			}
			else {
				s[a-1].score+=1;
				s[b-1].score+=1;
			}
		}
		qsort(s,n,sizeof(s[0]),cmp);
		for(i=0;i<n;i++)printf("%d ",s[i].number);
		printf("\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}