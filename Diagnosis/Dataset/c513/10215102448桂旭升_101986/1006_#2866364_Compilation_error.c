#include<stdio.h>
#include<string.h>
char B[100];
int f(void char *p, int c){
	int num, res = 0;
	while(*p){
		if(*p == '-')num = -1;
		if(*p == '1')num = 1;
		if(*p == '0')num = 0;
		res = res*3 + num;
		p++;
	}
	return res;
	
}

int main()
{
	int t, n, c, i;
	char *p;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%s", &B);
		c = strlen(B);
		p = &B;
		printf("%d", f(p, c));
		printf("\n");
	}
	return 0;
}