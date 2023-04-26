#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int T,R,sign=1;
	int V[100],a;
	for(;n--;n>0){
		sign=1,a=0;
		scanf("%d %d",&T,&R);
		if(T<0){
			sign=-1;
			T=-T;
		}		
		while(T>0){
			V[a]=T%R;
			
			T/=R;
			a++;
		}
		if(sign==-1)
			printf("-");
		for(;a--;a>0){
			if(V[a]<10){
				printf("%d",V[a]);
			}else{
				printf("%c",(char)(V[a]-10+'A'));
			}
			
		}
		printf("\n");
	}
	return 0;
} 