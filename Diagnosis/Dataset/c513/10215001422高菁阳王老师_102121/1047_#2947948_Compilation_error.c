#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[5000],c,cnt=1;
	int n,k,i,j;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		gets(s);
		int len1=strlen(s);
		printf("case #%d:\n",k);
		for(i=0;i<len1;i++){
			if(s[i]==s[i+1]) cnt++;
			if(s[i]!=s[i+1]&&cnt<=255){ printf("%d%c",cnt+1,s[i]);cnt=0}
			else if(s[i]!=s[i+1]&&cnt>=255) {printf("255%c",s[i]); cnt=0}
		}
		printf("\n");
	}
	return 0;
}