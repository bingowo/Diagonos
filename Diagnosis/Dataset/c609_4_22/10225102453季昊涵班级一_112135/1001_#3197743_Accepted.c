#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,R;
		int a[100];
		scanf("%d %d",&N,&R);
		if(N<0){
			printf("-");
			N=-1*N;
		}
			int i=0;
			while(N){
				int out=N%R;
				a[i]=out;
				N=N/R;
				i++;
			}
			for(int j=i-1;j>=0;j--){
				if(a[j]>=10)
				printf("%c",a[j]-10+'A');
				else
				printf("%d",a[j]);
				}
			printf("\n");

	}
	
	
	
	return 0; 
} 