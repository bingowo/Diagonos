#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int t,i,j,result;
    char s[100];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
    	scanf("%s",s);
    	result=0;
    	for(j=0;j<strlen(s);j++){
    		if(s[j]=='-')result=result*3-1;
    		else result=result*3+(s[j]-'0');
		}
		printf("case #%d:\n%d\n",i,result);
	}
	return 0;
}