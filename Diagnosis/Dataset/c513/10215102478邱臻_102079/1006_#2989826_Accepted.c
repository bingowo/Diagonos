#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,j,number,a;
	char s[10000];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",s);
		number=0;
		for(j=0;j<strlen(s);j++){
			if(s[j]=='-'){
				a=-1;
			}
			else a=s[j]-'0';
			number=number*3+a;
		}
		printf("case #%d:\n%d\n",i,number);
	} 
	return 0;
}