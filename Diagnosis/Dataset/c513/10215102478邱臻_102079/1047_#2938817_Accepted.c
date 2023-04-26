#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,j,count;
	char s[501];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		scanf("%s",s);
		printf("case #%d:\n",i);
		count=1;
		for(j=0;j<strlen(s)-1;j++){
			if(s[j]==s[j+1] && count<=254){
			    count++; //重复字符加一 
			}
			else {
				printf("%d%c",count,s[j]);
				count=1;
			}
		}
		if(s[j]==s[j-1])printf("%d%c\n",count,s[j]);
		else printf("1%c\n",s[j]);
			
	}
	return 0;
}