#include<stdio.h>
#include<string.h>

char O[60] = {'\0'};
char decimal[150];

int main()

{
    int j, t, i = 0, num, len, digit, temp;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
		scanf("%s", &O);
		num = 0;
		len = strlen(O) - 1;
		for(; len != 1; len--){
			digit = O[len] - '0';
			j = 0;
			do{
				if(j < num)temp = digit * 10 + decimal[j] - '0';
				else temp = digit *10;
				decimal[j++] = temp/8 + '0';
				digit = temp%8;
			}while(digit || j < num);
			num = j;
		}
    	decimal[num] = '\0';
    	printf("0.");
    	printf("%s\n", decimal);
	}
}
