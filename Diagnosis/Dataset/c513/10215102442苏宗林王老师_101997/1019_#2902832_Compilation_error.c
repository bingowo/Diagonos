#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int POINT[12] , win[12],lose[12];
int cmp(const void*a,const void*b ){
	int A=*(int *)a;
	int B=*(int *)b;
	if(POINT[A]!=POINT[B]){
	return (POINT[A]>POINT[B])?1:-1;
	}
	else{
		if(win[A]!=win[B]){
			return (win[A]>win[B]])?1:-1;
		}
		else{
			if(lose[A]!=lose[B]){
				return (lose[A]<lose[B])?1:-1;
			}
			else{
				return (A<B)?1:-1;
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
