#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double solve(){
	char s[101];
	scanf("%s",s);
	if(strchr("+-*/",s[0])){
		double p=solve();
		switch(s[0]){
			case '+':return p+solve();
			case '-':return p-solve();
			case '*':return p*solve();
			case '/':return p/solve();
		}
	}
	return atof(s);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;++i){
		printf("case #%d:\n%.6lf\n",i,solve());
	}
	return 0;
} 