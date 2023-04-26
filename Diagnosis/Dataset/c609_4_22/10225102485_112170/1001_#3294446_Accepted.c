#include<stdio.h>
int main(){
	int t,i,x,y,j,k;
	char m,a[100];
	scanf("%d\n",&t);
	int n,r;
	for(i=0;i<t;i++){
	    scanf("%d %d\n",&n,&r);
		if(n<0){
			printf("-");
			y=-n;
		}
		else y=n;
		j=0;
		while(y!=0){
			x=y%r;
			y=y/r;
			if(x<10) m=48+x;
			else m=55+x;
			a[j]=m;
			j++;
		}
		for(k=j-1;k>=0;k--) printf("%c",a[k]); 
		printf("\n");
	}
	return 0;
} 