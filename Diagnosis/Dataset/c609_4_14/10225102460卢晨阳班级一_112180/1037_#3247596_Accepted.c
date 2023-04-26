#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int maxlen=0;
	int start=0;
	int alpha[128];
	for(int i=0;i<128;i++) alpha[i]=-1;
	int t=0;
	char s[1000001];
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(alpha[s[i]]>=t){
			t=alpha[s[i]]+1;
			alpha[s[i]]=i;
		}else{
			alpha[s[i]]=i;
			if(maxlen<i-t+1){
				start=t;
				maxlen=i-t+1;
			}
		}
	}
	for(int i=start;i<start+maxlen;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
 } 