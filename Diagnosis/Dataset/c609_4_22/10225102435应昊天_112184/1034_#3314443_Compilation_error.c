#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<conio.h>
#define IN 1
#define OUT 0
int main(){
	char c;
	int state = OUT;                 	//十六进制数外 
	int flag = 0;
	unsigned sum = 0;
	while((c = getchar()) != EOF){
		//printf("%c\t%d\n",c,state);
		if(!state && c == '0'){
			if((c = getchar()) == 'x'){
				state = IN;
				flag = 1;	
			}
			else
				ungetch(c);
		}
		else if(state){
			if(isdigit(c))
				sum = sum * 16 + c - '0';
			else if(c >= 'a' && c <= 'f')
				sum = sum * 16 + c - 'a' + 10;
			else{
				if(sum)
					printf("%u ",sum);
				sum = 0;
				state = OUT;
			}
		}
	}
	if(sum != 0)
		printf("%d",sum);
	if(!flag)
		printf("%d",-1);
	return 0;
}