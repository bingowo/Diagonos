#include <stdio.h>
#include<string.h>
#include<ctype.h>
char s[60];
int ans = 0;
int con = 0;
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
    		if(isdigit(s[i])){
    			con++;
				if(ans < con)ans = con;
				//printf("%d %d\n",i, ans);
			}
			else{
    			con = 0;
			}
		}
		printf("%d", ans);
	}
    
	return 0;
}

		
	