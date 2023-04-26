#include<stdio.h>
int main(){
	int n,m;
	int a[105][105];
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			int ap[8];
			ap[0]=a[i][j]<=a[i-1][j-1]?1:0;
			ap[1]=a[i][j]<=a[i][j-1]?1:0;
			ap[2]=a[i][j]<=a[i+1][j-1]?1:0;
			ap[3]=a[i][j]<=a[i+1][j]?1:0;
			ap[4]=a[i][j]<=a[i+1][j+1]?1:0;
			ap[5]=a[i][j]<=a[i][j+1]?1:0;
			ap[6]=a[i][j]<=a[i-1][j+1]?1:0;
			ap[7]=a[i][j]<=a[i-1][j]?1:0;
			int ans=128*ap[0]+64*ap[1]+32*ap[2]+16*ap[3]+8*ap[4]+4*ap[5]+2*ap[6]+ap[7];
			for(int k=1;k<=7;k++){
				if(ans>128*ap[k%8]+64*ap[(k+1)%8]+32*ap[(k+2)%8]+16*ap[(k+3)%8]+8*ap[(k+4)%8]+4*ap[(k+5)%8]+2*ap[(k+6)%8]+ap[(k+7)%8])
				 ans=128*ap[k%8]+64*ap[(k+1)%8]+32*ap[(k+2)%8]+16*ap[(k+3)%8]+8*ap[(k+4)%8]+4*ap[(k+5)%8]+2*ap[(k+6)%8]+ap[(k+7)%8];
			}
			printf("%d ",ans);
		}
		printf("\n");
	}
}