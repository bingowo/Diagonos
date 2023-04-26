#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float eval(){
	char s[101];
	scanf("%s",s);
	if(strchr("+-*/",*s)){
		float opd1=eval();
		switch(*s){
			case'+':return opd1+eval();
			case'-':return opd1-eval();
			case'*':return opd1*eval();
			case'/':return opd1/eval();
		}
	}
	return atof(s);
}

int main(){
	int i,T,n;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		printf("%f\n",eval());
	}
	return 0;
}