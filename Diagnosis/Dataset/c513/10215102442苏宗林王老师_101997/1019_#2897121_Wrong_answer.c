#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int POINT[12] , win[12],lose[12];
int cmp(const void*a,const void*b ){
	
	if(POINT[*(int *)a]!=POINT[*(int *)b])return -POINT[*(int *)a]+POINT[*(int *)b];
	else {
		if(win[*(int *)a]!=win[*(int *)b])return win[*(int *)a]-win[*(int *)b];
		else{
			if(lose[*(int *)a]!=lose[*(int *)b])return lose[*(int *)a]-lose[*(int *)b];
			else{
				return *(int *)b-*(int *)a;
			}
		}
	}
}
int main(){
	int i,n,k,m,a,b,c,TEAM[12];
	while(scanf("%d%d",&n,&m)==2){
		
		for(int j=0;j<n;j++){
		TEAM[j]=j+1;
		POINT[j]=0;
		win[j]=0;
		lose[j]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
			if(0==c){
				POINT[a]++;
				POINT[b]++;
			}
			else if(-1==c){
				POINT[b]+=3;
				POINT[a]-=1;
				win[b]++;
				lose[a]++;
			}
			else{
				POINT[a]+=3;
				POINT[b]-=1;
				win[a]++;
				lose[b]++;
			}
			
		}
		qsort(TEAM,n,sizeof(int),cmp);
		for(k=0;k<n;k++){
			printf("%d ",TEAM[k]);
				
			
		}
		printf("\n");
	}
	
		return 0;
	}
