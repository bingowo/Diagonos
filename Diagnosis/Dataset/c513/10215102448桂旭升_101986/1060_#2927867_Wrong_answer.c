#include <stdio.h>
#include<string.h>
#include<ctype.h>
char s[120];
int ans = 0;
int con = 0;
int C(int i, int len){
	char c[120];
	int j = 0;
	for(j = 0;j < 120; j++){
		c[j] == '\0';
	}
	j = 0;
	for(;i < len; i++){
		if(isdigit(s[i])){
			c[j] = s[i];j++;printf("%d\n", ans);
		}
		if(isalpha(s[i])) break;
	}
	j = 0;
	while(c[j]=='0')j++;
	if(strlen(c)-j>ans)ans = strlen(c)-j;
	return strlen(c);
}
int main(){
	int i, flag = 0, len;
    gets(s); len = strlen(s);
    for(i = 0; i< len; i++){
    	if(isdigit(s[i])){
    		flag = 1;break;
		}
    }
    if(flag == 0)printf("0");
    else{
    	for(; i< len; i++){
    		i += (C(i, len) - 1);
		}
		printf("%d", ans);
	}
    
	return 0;
}

		
	