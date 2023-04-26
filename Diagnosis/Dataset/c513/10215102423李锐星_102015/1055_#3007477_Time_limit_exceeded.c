#include <stdio.h>
#include <string.h>
#define L 1000000

int main()
{
	char s[L+1];
	scanf("%s",s);
	int letter[128];
	int i;
	for (i=0;i<128;i++) letter[i]=-1;
	int start=0;
	int maxlen=0;
	int t=0;
	for (i=0;i<strlen(s);i++){
		int a=s[i];
		if(letter[a]>=t){
			t=letter[a]+1;
			letter[a]=i;
		}
		else{
			letter[a]=i;
			if(maxlen<i-t+1){
				start=t;
				maxlen=i-t+1;
			}
		}
	} 
	for (i=start;i<start+maxlen;i++){
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}