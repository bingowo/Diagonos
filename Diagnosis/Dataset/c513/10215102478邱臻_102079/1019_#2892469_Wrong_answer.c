#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(const void*p1,const void*p2){
	int *a,*b;
	if(((int*)p1)[0]==((int*)p2)[0])return(((int*)p2)[1]-((int*)p1)[1]);
	else return(((int*)p2)[0]-((int*)p1)[0]);
}

int main() {
	int n,m,i,j,k,a,b,z,c,team[11][3],score[11][3]={0};
	do{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++){
			for(j=0;j<3;j++){
				scanf("%d",&team[i][j]);
			}  //每一局的情况 
			a=team[i][0]-1;b=team[i][1]-1;c=team[i][2];
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
		for(z=0;z<n;z++)score[z][2]=z+1;
		qsort(*score,n,sizeof(int),cmp);
		for(k=0;k<n;k++){
			printf("%d ",score[k][2]);
		}
		printf("\n");
	}while(m!=0 && n!=0);
	return 0;
}