#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		int a,b,c,n;
		scanf("%d %d",&a,&b);
		c=a^b;
		n=0;
		while(c){
			c=c&(c-1);
			n++;
		}
		printf("%d\n",n);
	}
	return 0;
}