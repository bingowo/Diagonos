#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int T,R,sign=1;
	int V[100],a=0,r;
	for(;n--;n>0){
		printf("here");
		scanf("%d %d",&T,&R);
		if(T<0){
			sign=-1;
		}
		
		while(T>0){
			r=T%R;
			if(r<10){
				V[a]=r;
			}else{
				V[a]=(char)(r-10+'A');
			}
			T/=R;
			a++;
		}
		if(sign==-1)
			printf("-");
		for(;a--;a>=0){
			printf("%d",V[a]);
		}
		printf('\n');
	}
	return 0;
} 