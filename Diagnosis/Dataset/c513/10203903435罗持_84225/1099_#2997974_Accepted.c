#include <stdio.h>
#include <string.h>
int T;
char table[36][10] = {".-","-...","-.-.","-..",".","..-.","--.","....",
				"..",".---","-.-",".-..","--","-.","---",".--.",
				"--.-",".-.","...","-","..-","...-",".--","-..-",
				"-.--","--..","-----",".----","..---","...--","....-",
				".....","-....","--...","---..","----."};
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		char s[1010] = {0};
		char res[1010] = {0};
		char buf[10] = {0};
		scanf("%s",s);
		int len = 0;
		int pos = 0;
		while(pos<strlen(s)){
			if(s[pos]=='/'){
				int st = pos;
				int cnt = 0;
				while(st<strlen(s) && s[st]=='/'){
					st++;
					cnt++;
				}
				if(cnt==1);
				else if(cnt==3) res[len++] = ' ';
				else if(cnt==5) res[len++] = '.';
				pos = st;
			}
			else{
				int st = pos;
				int idx = 0;
				while(st<strlen(s) && s[st]!='/'){
					buf[idx++] = s[st];
					st++;
				}
				buf[idx] = '\0';
				//printf("%s ",buf);
				for(int i=0;i<36;i++){
					if(strcmp(buf,table[i])==0){
						//printf(" find ");
						if(i<26) res[len++] = i+'A';
						else res[len++] = i-26+'0';
						break;
					}
				}
				//printf("%c\n",res[len-1]);
				pos = st;
			}
		}
		res[len] = '\0';
		printf("case #%d:\n",kase);
		printf("%s\n",res); 
	}
	return 0;
}