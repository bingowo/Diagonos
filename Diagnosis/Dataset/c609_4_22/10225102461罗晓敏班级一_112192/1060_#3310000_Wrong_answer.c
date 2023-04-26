#include <stdio.h>
#define cnt 100 
int main(){
    char s[cnt+1];scanf("%s",s);
    int i;
    for(i=0;s[i];i++){
    	if(s[i]<s[i+1]){
    		printf("%c",s[i]);
    		printf("%c",s[i]);
		}else if(s[i]>s[i+1]){
			printf("%c",s[i]);
		}else{
			int j,count=1;
			for(j=i;s[j]&&s[j]==s[j+1];j++){
				count++;
				printf("%c",s[i]);
			}
			if(s[j+1]>s[j]){
				int k;
				for(k=0;k<count;k++){
					printf("%c",s[i]);
				}
				i=j;
			}else{
				printf("%c",s[i]);
				i=j;
			}
		}
	}
}