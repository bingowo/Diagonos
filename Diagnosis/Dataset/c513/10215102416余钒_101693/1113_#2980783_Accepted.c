#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int k,n;
int num[105][1005],top[105];
int main() {
	scanf("%d%d",&k,&n);
	top[2]=top[1]=1;
	num[2][1]=1;
	for(int i=3;i<=n;i++){
		int p=i-k;
		if(p<=0) p=1;
		for(int j=p;j<i;j++)
			for(int k=1;k<=top[j];k++)
				num[i][k]+=num[j][k];
		int tp=0;
		for(int j=1;j<=1000;j++){
			if(num[i][j]>0) tp=j;
			num[i][j+1]+=num[i][j]/10,num[i][j]%=10;
		} 
		top[i]=tp;
	}
	for(int i=top[n];i;i--) printf("%d",num[n][i]);
	return 0;
}