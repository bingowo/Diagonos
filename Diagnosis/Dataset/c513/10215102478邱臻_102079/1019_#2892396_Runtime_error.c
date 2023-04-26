#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(const void*x,const void*y){
	int *p1,*p2;
	p1=*(int**)x;p2=*(int**)y;
	if(p1[0]==p2[0])return(p2[1]-p1[1]);
	else {
		return(p2[0]-p1[0]);
	}
}

int main() {
	int n,m,i,j,k,a,b,c,team[11][3],score[11][2]={0};
	do{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++){
			for(j=0;j<3;j++){
				scanf("%d",&team[i][j]);
			}  //每一局的情况 
			a=team[i][0];b=team[i][1];c=team[i][2];
			if(c==1){
				score[a][0]+=3;score[a][1]++;
				score[b][0]-=1;
			}
			else if(c==-1){
				score[a][0]-=1;
				score[b][0]+=3;score[b][1]++;
			}
			else if(c==0){
				score[a][0]++;score[b][0]++;
			}   //每一局的积分情况 
		}  //输入一场比赛的结果 
		qsort(*score,m+1,sizeof(int),cmp);
		for(k=0;k<m;k++){
			printf("%d ",k);
		}
		printf("\n");
	}while(m!=0 && n!=0);
	return 0;
}