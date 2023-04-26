#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		int l = strlen(str), flag1 = 0, flag2 = 0, flag3 = 0, flag = 1;
		for(j = 0; j < l; ++j){
			if((str[j] == '{' && !flag2) || (str[j] == '{' && flag3))	flag1 += 1;
			else if((str[j] == '[' && !flag3) || (str[j] == '[' && flag1))	flag2 += 1;
			else if((str[j] == '(' && !flag1) || (str[j] == '(' && flag2))	flag3 += 1;
			else if(str[j] == '}')	flag1 -= 1;
			else if(str[j] == ']')	flag2 -= 1;
			else if(str[j] == ')')	flag3 -= 1;
			else{
				flag = 0;
				break;
			}
		}
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}