#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include<stdlib.h>
int main(){
	int tab[256] = {0};
	char* s = (char*)malloc(sizeof(char) * 1000000);
	scanf("%s",s);
	int state = 0;
	int maxlen = 1;
	int maxstart = 0;
	int maxend = 0;
	int start = 0;
	int end = 0;
	int len = 1;
	for(int i = 0;s[i] != '\0';i++){
		if(tab[s[i]] == 0){
			if(state){
				end++;
				len++;
			}
			else{
				state = 1;
				start = i;
				end = i;
			}
		}
		else{
			if(state){
				if(len > maxlen){
					maxlen = len;
					maxstart = start;
					maxend = end;
				}
				len = 1;
				state = 0;
			}
		}
		tab[s[i]]++; 
	}
	if(state){
		end = strlen(s) - 1;
		if(len > maxlen){
			maxlen = len;
			maxstart = start;
			maxend = end;
		}
	}
	for(int j = maxstart;j <= maxend;j++){
		putchar(s[j]);
	}
	return 0;
}