#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[5][5]={1},re[5][5],n,k;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
		int i,j;
		for(i=1;i<4;i++){
			for(j=1;j<4;j++){
		scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<4;i++){
			for(j=1;j<4;j++){
			re[i][j]=1;
			}
		}
		for(i=1;i<4;i++){
			for(j=1;j<4;j++){
			if(a[i][j]%2==0);
			else{
				re[i][j]=re[i][j]^1;
				re[i][j+1]=re[i][j+1]^1;
				re[i][j-1]=re[i][j-1]^1;
				re[i+1][j]=re[i+1][j]^1;
				re[i-1][j]=re[i-1][j]^1;
				
			}	
			}
		}
		for(i=1;i<4;i++){
			for(j=1;j<3;j++){
				printf("%d ",re[i][j]);
			}printf("%d\n",re[i][j]);
		}
	}
	
	return 0;
}