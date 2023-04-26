#include<stdio.h>
#include<string.h>
int main(){
	char s[51];
	scanf("%s",s);
	int cnt = 1;
	int maxcnt = 1;
	char c = s[0];
	for(int i = 1;s[i] != '\0';i++){
		if(s[i] == c){
			if(cnt > maxcnt)
				maxcnt = cnt;
			cnt = 1;
		}else{
			cnt++; 
		}
		c = s[i];	
	}
	printf("%d\n",maxcnt);
	return 0;
}