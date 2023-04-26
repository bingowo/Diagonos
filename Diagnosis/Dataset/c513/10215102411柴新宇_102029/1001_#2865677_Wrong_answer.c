#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char table[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int T;
	scanf("%d",&T);
	int n=0;
	while(n<T){
	
	int j;
	int ans[32];
	int i=0;
	int N,R;
	scanf("%d",&N);
	scanf("%d",&R);
	while(N<0){
		N*=(-1);
		printf("-");
	}
	do
{

		ans[i]=N%R;
		i++;
		N=N/R;
			
}while(N!=0);

	int cout;

for(i--;i>=0;i--){
	cout=ans[i];
	printf("%c",table[cout]);
	
}
	printf("\n");
	n++;}
	return 0;
}