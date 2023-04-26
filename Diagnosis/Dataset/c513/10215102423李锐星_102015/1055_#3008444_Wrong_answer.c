#include <stdio.h>
#include <string.h>
#define L 1000000

int main()
{
	char s[L+1];
	scanf("%s",s);
	int maxlen=0;
	int start=0;
	for (int t=0;t<strlen(s);t++){
		int alpha[128]={0};
		int len=0;
		for (int i=0;i<strlen(s)&&alpha[s[i]]==0;i++){
			alpha[s[i]]=1;
			len++;
		}
		if(maxlen<len){
			start=t;
			maxlen=len;
		}
	}
	for (int i=start;i<start+maxlen;i++){
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}