#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

double f(){
	char s[120];
	scanf("%s", &s);
	switch(s[0]){
		case'+': return f() + f(); break;
		case'-': return f() - f(); break;
		case'*': return f() * f(); break;
		case'/': return f() / f(); break;
		default: return atof(s);
	}
}
int main(){
	int i, wide = 1, num, cnt = 0, ans = 0, j, t;
	char c;
	scanf("%d", &t);
    for(i = 0; i< t; i++){
    	printf("case #%d:\n", i);
    	printf("%.6f\n", f());
    }
	return 0;
}