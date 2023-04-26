#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[1010] = {0};
char t[2010] = {0};
int main(void)
{
	scanf("%s",s);
	int len = strlen(s);
	int wei = 1005;
	t[wei++] = s[0];
	int tou = wei-1;
	for(int i=1;i<len;i++)
	{
		char head = t[tou];
		if(s[i]>=head){
			tou--;
			t[tou] = s[i];
		} 
		else {
			wei++;
			t[wei] = s[i];
		}
	}
	for(int i=tou;i<=wei;i++)
		if(isalpha(t[i])){
			if(t[i]>='a') t[i] = t[i]-'a'+'A';
			printf("%c",t[i]);
		} 
	return 0;
}