#include <stdio.h>
#include <math.h>

int main(){
	int T,N,R;
	int n[32];
	scanf("%d",&T);
	while(scanf("%d %d",&N,&R)!=EOF){
		if(N==0){
			printf("%d",0);
			continue;
		}
		int x=abs(N),digit=0;
		while (x){
			n[digit]=x%R;
			x/=R;
			digit++; 
		}
		if (N<0){
			printf("%c",'-');
		}
		for(int i=digit-1;i>=0;i--){
			if (n[i]<10){
				printf("%d",n[i]);
			}
			else if (n[i]>=10){
				char y='A'+(n[i]-10);
				printf("%c",y);
			}
		}
	}
	return 0;
}