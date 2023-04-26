#include<stdio.h>
int main(){
	int t,i,x,y;
	char m;
	scanf("%d\n",&t);
	int n[t],r[t];
	for(i=0;i<t;i++) scanf("%d %d\n",&n[i],&r[i]);
	for(i=0;i<t;i++){
		if(n[i]<0) printf("-");
		y=n[i];
		while(y!=0){
			x=y%r[i];
			y=y/r[i];
			if(x<10) printf("%d",x);
			else{
			    m=55+x;
			   	printf("%c",m);
			} 
		}
		printf("\n");
	}
	return 0;
} 