#include <stdio.h>
int main(){
	int a,n,m,x;scanf("%d%d%d%d",&a,&n,&m,&x);
	int num[2][38];
	num[0][0]=a;num[1][0]=0;
	num[0][1]=a;num[1][1]=0;
	num[0][2]=0;num[1][2]=1;
	num[0][3]=a;num[1][3]=0;
	int i;
	for(i=4;i<(n-1)*2;i+=2){
		num[0][i]=num[0][i-4]+num[0][i-2];
		num[1][i]=num[1][i-4]+num[1][i-2];
		num[0][i+1]=num[0][i-1]+num[0][i-4];
		num[1][i+1]=num[1][i-1]+num[1][i-4];
	}
	int y=(m-num[0][i-1])/num[1][i-1];
	printf("%d",num[0][2*x-1]+num[1][2*x-1]*y);
}