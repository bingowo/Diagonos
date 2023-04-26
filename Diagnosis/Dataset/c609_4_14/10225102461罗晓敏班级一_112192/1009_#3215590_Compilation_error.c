#include <stdio.h>
#include <string.h>
int f1(char a){
	int i,ret=0;
	for(i=0;i<8;i++){
		if(a>>i&1==1){
			ret++;
		}
	}
	return ret;
}
int f2(int a,int b){
	int c;
	while(b!=0){
		c=a;
		a=b;
		b=c%b;
	}
	return a;
}
int main(){
	int n,i,j,numerator,denominator;
	scanf("%d",&n);
	char s[120];
	for(i=0;i<n;i++){
		numerator=0;
		gets(s);
		for(j=0;s[j];j++){
			numerator+=f1(s[j]);
		}
		denominator=j*8;
		q=f2(denominator,numerator);
		printf("%d/%d\n",numerator/q,denominator/q);
	}
}