#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
double num[110];
int main(){
	int t, i, j;
	scanf("%d", &t);
	gets(str);
	for(i = 0; i < t; ++i){
		gets(str);
		int l = strlen(str), top = 0, flag = 0;
		for(j = l - 1; j >= 0; --j){
			if(str[j] == ' ' && flag){
				num[top++] = atof(str + j);
				flag = 0; 
			}
			if(str[j] >= '0' && str[j] <= '9')	flag = 1;
			if(str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/'){
				if(str[j] == '+'){
					num[top-2] = num[top-1] + num[top-2];
				}
				else if(str[j] == '-'){
					num[top-2] = num[top-1] - num[top-2];
				}
				else if(str[j] == '*'){
					num[top-2] = num[top-1] * num[top-2];
				}
				else{
					num[top-2] = num[top-1] / num[top-2];
				}
			}
		}
		printf("case #%d:\n%.6f\n", i, num[0]);
	}
	return 0;
}