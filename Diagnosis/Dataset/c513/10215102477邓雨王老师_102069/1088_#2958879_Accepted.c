#include<stdio.h>
long long map[40][40]={0};  //二维数组中前一个参数表示m,后一个参数表示n 
void solve(){
	int i,j;
	for(i=1;i<=40;i++) map[i][0]=1,map[i][i]=1;
	for(i=2;i<=40;i++){
		for(j=1;j<i;j++) map[i][j]=map[i-1][j-1]+map[i-1][j];
	}
}
int main(){
	solve(); 
	int chance;
	scanf("%d",&chance);
	int i;
	int m,n;
	for(i=0;i<chance;i++){
		scanf("%d%d",&m,&n);
		printf("case #%d:\n",i);
		printf("%lld\n",map[m][n]);
	}
}