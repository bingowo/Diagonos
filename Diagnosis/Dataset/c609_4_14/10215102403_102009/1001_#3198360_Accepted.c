#include<stdio.h>
int main(){
	int T; char a[32];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		int N,R,j=0,sign=1;
		scanf("%d %d\n",&N,&R);
		if(N<0) {N*=-1;sign=-1;}
		while(N!=0){
			if(N%R>=10) a[j]='A'+N%R-10;	
		 	else a[j]='0'+N%R;
			N=N/R; j++;
		}
		int count=j;
		if(sign==-1) printf("-");
		for(j=count-1;j>=0;j--) printf("%c",a[j]);
		printf("\n");
	}
}