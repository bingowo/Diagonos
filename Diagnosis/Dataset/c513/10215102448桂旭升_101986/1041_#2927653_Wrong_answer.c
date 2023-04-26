#include <stdio.h>
#include<string.h>

char s[60];
int ans = 1;
int con = 1;
int main(){
	int i, flag = 0, len;
    gets(s); len = strlen(s);
    for(i = 0; i< len; i++){
    	if(s[i] != s[0])flag = 1;
    }
    if(flag == 0)printf("1");
    else{
    	for(i = 0; i< len; i++){
    		if(s[i-1] != s[i]){
    			con++;
			}
			if(s[i-1] == s[i]){
    			if(ans < con)ans = con;con = 1;
			}
		}
		printf("%d", ans);
	}
    
	return 0;
}

		
	