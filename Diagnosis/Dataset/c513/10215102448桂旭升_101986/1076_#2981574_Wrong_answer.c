#include<stdio.h>
#include<string.h>
int a[102] = {0};
char s[101];
int main(){
	int t, len, j, k = 1;
	scanf("%d", &t);gets(s);
	for(int i = 0; i < t; i++){
		gets(s); len = strlen(s);
		for(j = 0; j < len; j++){
			if(j == 0){
				if(s[j] == '(')a[k++] = 1;
				if(s[j] == '[')a[k++] = 2;
				if(s[j] == '{')a[k++] = 3;
			}
			else{
				if(a[k-1] == 1 && s[j] == ')'){
					k--;
				}
				else if(a[k-1] == 2 && s[j] == ']'){
					k--;
				}
				else if(a[k-1] == 3 && s[j] == '}'){
					k--;
				}
				else if((a[k-1] == 2 || a[k-1] == 3) && s[j] == '{'){
					printf("No"); break;
				}
				else if((a[k-1] == 1 || a[k-1] == 3) && s[j] == '('){
					printf("No"); break;
				}
				else if((a[k-1] == 2 || a[k-1] == 1) && s[j] == '['){
					printf("No"); break;
				}
				else{
					if(s[j] == '(')a[k++] = 1;
					if(s[j] == '[')a[k++] = 2;
					if(s[j] == '{')a[k++] = 3;
				}
			}
		}
		if(k == 1)printf("Yes");
		if(i != t-1)printf("\n");
	}
	return 0;
}