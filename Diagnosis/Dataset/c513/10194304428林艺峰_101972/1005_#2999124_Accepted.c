#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char decimal[210], num[210];
int main(){
	int t, i, j, numbers, len, digit, temp;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		memset(decimal, 0, sizeof(decimal));
		scanf("%s", num);
		numbers = 0;
		len = strlen(num) - 1;
		for(; len != 1; --len){
    		digit = num[len] - '0';
    		j = 0;
    		do{
        		if (j < numbers)
        		    temp = digit*10 + decimal[j] - '0';
       			else
        		    temp = digit*10;
        		decimal[j++] = temp/8 + '0';
        		digit = temp%8;
    		}while (digit!=0 || j < numbers);
    		numbers = j;
    	}
		printf("case #%d:\n0.%s\n", i, decimal);
	}
	return 0; 
}