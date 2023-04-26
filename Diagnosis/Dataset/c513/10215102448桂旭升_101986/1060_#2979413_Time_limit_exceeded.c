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
    		cnt = cnt*10 + s[i]-'0';
    		if(cnt > con)con = cnt;
		}
		else{
			cnt = 0;
		}
    }
    while(wide <= con){
    	ans++; wide *= 10;
	}
	printf("%d", ans);
	return 0;
}

		
	