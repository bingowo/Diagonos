#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
0~9 --> 0 -- 9
A~Z --> 10 -- 35
a~z --> 36 -- 61
*/

int ChangeIndex(char c)
{
	int ret;
	if(isdigit(c)){
		ret = c - '0';
	}else if(isupper(c)){
		ret = c - 'A' + 10;
	}else{
		ret = c - 'a' + 36;
	}
	
	return ret;
}

int main(void)
{
	char s[61];
	int isFind[62], CroNum[62];
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		memset(isFind, -1, sizeof(isFind));
		memset(CroNum, -1, sizeof(CroNum));
		scanf("%s", s);
		int len = strlen(s);
		for(int j = 0 ; j < len; j ++){
			isFind[j] = ChangeIndex(s[j]);
		}
		int Number = 0, outNum = 0;
		for(int j = 0 ; j < len; j ++){
			if(CroNum[isFind[j]] == -1){
				if(j == 0){
					CroNum[isFind[j]] = 1;
				}else if(j != 0 && Number == 0){
					CroNum[isFind[j]] = Number;
					Number = 2;
				}else{
					CroNum[isFind[j]] = Number;
					Number ++;
				}
			}
		}
		for(int j = 0 ; j < len ; j ++){
			outNum = outNum * Number + CroNum[isFind[j]];
		}
		printf("case #%d:\n", i);
		printf("%d\n", outNum);
	}
	
}