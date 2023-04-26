#include<stdio.h>
#include<string.h>
int main(void)
{
	int A,B,i;
	char big[100]={0};
	char small[100]={0};
	scanf("%d%d",&A,&B);
	
	int C = A % B;//分割整数和小数
	A = (A-C) / B;
	if(C == 0){//处理小数部分
		i = 0;
		small[i] = '0';
		i++;
	}
	else{
		for(i = 0; C > 0; i++){
			small[i] = (C%3) + '0';
			C /= 3;
		}
	}
	small[i] = '.';
	small[i+1] = '\0';
	//printf("%s\n",small);
	
	if(A == 0){//整数部分
		i = 0;
		big[i] = '0';
		i++;
	}
	else{
		for(i = 0; A != 0; i++){
        	big[i] = A%3+'0';
        	A /= 3;
    	}
	}
	big[i] = '\0';
	//printf("%s\n",big);
	
    char *out = strcat(small,big);
    char *test = out;
    int plus = 0;
    //printf("%s",out);
    for(test = out; *test != '\0'; test++){//三进制加法
    	if(*test == '.') continue;
    	*test = *test + 1 + plus;
    	plus = 0;
    	if(*test >= '3'){
    		plus = 1;
    		*test -= 3;
		}
	}
	if(plus == 1){//最高位进位
		*test = '2';
		*(test+1) = '\0';
	}
	
	//printf("%s\n",out);
	for(test = out; *test != '\0'; test++){//按位相减
		switch(*test){
			case '.': break;
			case '0':*test = '2';break;
			case '1':*test = '0';break;
			case '2':*test = '1';break;
		}
	}
	
	for(test--; test >= out; test--){//处理整数部分的0
		if(*test == '0') *test = '\0';
		else break;
	}
	for(test = out; *test != '\0'; test++){//处理小数部分的0
		if(*test == '0') out++;
		else break;
	}
	
	for(test = out; *test != '\0'; test++);
	if(*out == '.') out++;
	for(test--; test >= out; test--){
		putchar(*test);
	}
	
	return 0;
}