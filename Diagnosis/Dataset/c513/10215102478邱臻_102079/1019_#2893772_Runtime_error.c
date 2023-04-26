#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(const void*p1,const void*p2){
	int *a=(int*)p1,*b=(int*)p2;
	if(a[0]!=b[0]){
		return (b[0]-a[0]);
	}
	else{
		if(a[1]!=b[1]){
			return(b[1]-a[1]);
		}
		else{
			if(a[2]!=b[2])return (a[2]-b[2]);
			else return (a[3]-b[3]);
		}
	}
	
}

int main() {
	int n,m,i,j,k,a,b,z,c,team[11][3];
	int score[11][4];
	do{
		for(i=0;i<11;i++){
		    for(j=0;j<3;j++)team[i][j]=0;
		    for(k=0;k<4;k++)score[i][k]=0;
		} 
		scanf("%d %d",&n,&m);
		if(m==0 && n==0)break;
		for(i=0;i<m;i++){
			for(j=0;j<3;j++){
			scanf("%d",&team[i][j]);
			}  //每一局的情况 
		    a=team[i][0]-1;b=team[i][1]-1;c=team[i][2];
			if(c==1){
				score[a][0]+=3;score[a][1]++;
				score[b][0]-=1;score[b][2]++;
			}
			else if(c==-1){
				score[a][0]-=1;score[a][2]++;
				score[b][0]+=3;score[b][1]++;
			}
			else if(c==0){
				score[a][0]++;score[b][0]++;
			}   //每一局的积分情况 
		}  //输入一场比赛的结果 
		for(z=0;z<n;z++)score[z][3]=z+1;
		qsort(score,n,sizeof(score[0]),cmp);
		for(k=0;k<n;k++){
			printf("%d ",score[k][3]);
		}
		printf("\n");
	}while(m!=0 || n!=0);
	return 0;
}