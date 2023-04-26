#include <stdio.h>
#include<string.h>
#include<ctype.h>
char s[120];
int con = 0;

int main(){
	int i, wide = 1, len, cnt = 0, ans = 0;
    gets(s); len = strlen(s);
    for(i = 0; i< len; i++){
    	if(isdigit(s[i])){
    		if(cnt != 0 || s[i] != '0'){
    			con++; cnt += s[i]-'0';
    			if(con > ans)ans = con;
			}
		}
		else{
			cnt = 0; con = 0;
		}
    }
	printf("%d", ans);
	return 0;
}

		
	