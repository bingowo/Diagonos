#include <stdio.h>

int main() {
	int N,R;
	scanf("%d%d",&N,&R);
	char c[37],res[33];
	int i;
	for(i=0;i<10;i++){
		c[i]=i+'0';
	}
	for(i=10;i<36;i++){
		c[i]=i+'A'-10;
	}
	int t=0;
	if(N==0)res[t++]='0';
	
	int a=0,b=0;
	while(N!=0){
		a=N/R;
		b=N%R;
		if(b<0){
			a++;
			b-=R;
		}
		res[t++]=c[b];
		N=a;
	}
	int j;
	for(j=t-1;j>=0;j--){
		printf("%c",res[j]);
	}
	
	return 0;
}
