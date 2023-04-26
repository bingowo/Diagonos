#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#define IN 1
#define OUT 0
int main(){
	char c;
	int state = OUT;                 	//十六进制数外 
	int flag = 0;
	unsigned sum = 0;
	int iszero = 0;                      //考虑输出16进制值为0情况 
	c = getchar();
	while(c != EOF){
		//printf("%c\t%d\n",c,state);
		if(!state && c == '0'){
			if((c = getchar()) == 'x'){   //出现0x不一定保证出现合法16进制数 
				state = IN; 
				c = getchar();
			}
		}
		else if(state){
			if(isdigit(c)){
				sum = sum * 16 + c - '0';
				iszero = 1;	
			}
			else if(c >= 'a' && c <= 'f')
				sum = sum * 16 + c - 'a' + 10;
			else{
				if(sum || iszero){                              	//未包含值为0情况 
					printf("%u ",sum);
					flag = 1;	
				}
				sum = 0;
				iszero = 0;
				state = OUT;
			}
			c = getchar();
		}
		else
			c = getchar();
	}
	if(sum != 0 || iszero){
		printf("%d",sum);
		flag = 1;	
	}
	if(!flag)
		printf("%d",-1);
	return 0;
}