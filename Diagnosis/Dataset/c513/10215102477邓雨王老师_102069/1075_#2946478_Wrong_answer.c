#include<stdio.h>
int main(){
	int m,n;   //分别代表行和列 
	scanf("%d%d",&m,&n); 
	long long map[m][n];     //存储要求的最短路径 
    long long map1[m][n];    //存储输入的矩阵 
    int i,j;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++) scanf("%lld",&map1[i][j]);
	}
	map[0][0]=map1[0][0]; 
    for(i=1,j=0;i<m;i++) map[i][j]=map1[i][j]+map[i-1][j];
    for(j=1,i=0;j<n;j++) map[i][j]=map1[i][j]+map[i][j-1]; 
    for(i=1;i<m;i++){
    	for(j=1;j<n;j++) map[i][j]=(map[i-1][j]<map[i][j-1])?map[i-1][j]+map1[i][j]:map[i][j-1]+map1[i][j];
	}
	printf("%lld",map[m-1][n-1]);
}