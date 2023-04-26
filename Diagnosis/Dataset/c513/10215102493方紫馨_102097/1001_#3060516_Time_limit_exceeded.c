#include<stdio.h>
int main()
{
	int T,N,R;
	scanf("%d",&T);
	while(T>0){
		int val[100],a=0;
		scanf("%d%d",&N,&R);
		if(N<0){
			printf("-");
			N=-N;
		}
		while(N>0){
			val[a++]=N%R;
			N/=R;
		}
		while(a>0){
			if(val[a-1]>=10){
				printf("%c",val[a-1]-10+'A');
			}else{
				printf("%d",val[a-1]);
			}
			a--;		
		}
		printf("\n");
	}
	return 0;
} 