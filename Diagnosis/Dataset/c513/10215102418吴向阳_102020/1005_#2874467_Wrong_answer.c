#include <stdio.h>
#include <math.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		char s[53];
		scanf("%s",s);
		char *p=s;
		*p++;
		double number=0;
		int a=-1;
		while(*++p){
			number=number+(*p-'0')*pow(8,a);
			a--;
		}
		printf("case #%d:\n%f\n",i,number); 
	}
	return 0;
}