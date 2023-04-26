#include<stdio.h> 
#include<string.h>
#include<math.h>
void solve(int s[3][3],int x,int y){
	int i,j;
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<=y+1;j++){
			if(i>=0&&i<=2&&j>=0&&j<=2&&abs(i-x)+abs(j-y)<=1){
				if(s[i][j]==1) s[i][j]=0;
				else s[i][j]=1;
			}
		}
	}
}
int main(){
	int chance;
	scanf("%d",&chance);
	int t,i,j;
	for(t=0;t<chance;t++){
		int s[3][3]={1,1,1,1,1,1,1,1,1};
		int c[3][3];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				scanf("%d",&c[i][j]);
				if(c[i][j]%2==1) {solve(s,i,j);/*printf("(%d,%d)\n",i,j);*/}
			}
		}
		printf("case #%d:\n",t);
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d ",s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}