#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n,m,D,mp[205][205];
char s[10];

void rotate(){
	int tmp[205][205],tn,tm;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			tmp[j][n-i+1]=mp[i][j];
		}
	tn=m,tm=n;
	for(int i=1;i<=tn;i++)
		for(int j=1;j<=tm;j++)
			mp[i][j]=tmp[i][j];
	m=tm,n=tn;
}
int main() {
	scanf("%d%d%d%s",&m,&n,&D,s);
	D%=360;
	if(s[0]=='L') D=-D;
	while(D<0) D+=360;
	D/=90;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int i=1;i<=D;i++) rotate();
	printf("%d %d\n",m,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d ",mp[i][j]);
		puts("");
	}
	return 0;
}