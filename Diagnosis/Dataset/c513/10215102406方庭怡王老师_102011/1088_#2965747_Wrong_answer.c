#include<stdio.h>
#define MAXN 100
long long A[MAXN][MAXN];
void init(){
	for(int i=0;i<MAXN;i++){
		A[i][0]=A[i][i]=1;
	}
	for(int i=2;i<MAXN;i++){
		for(int j=1;j<i;j++){
			A[i][j]=A[i-1][j-1]+A[i-1][j];
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	init();
	for(int i=0;i<T;i++){
		printf("case #%d:\n",i);
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		printf("%d\n",A[a][b]);
	}
	return 0;
}