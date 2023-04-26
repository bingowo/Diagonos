#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[10000];
	char result[10000]="0";
	int flag=0,n=0,p,z=0,i,j;
	scanf("%s",s);  //输入字符串
	for(i=0;i<strlen(s);i++){
		if(!isdigit(s[i])){
			result[z++]=s[i];
		}
		else if(!isdigit(s[i+1]) || i==strlen(s)-1){
			flag=1;n=n*10+s[i]-'0';
			for(j=0;j<n;j++){
				for(p=0;p<z;p++)printf("%c",result[p]);
			}
			n=0;z=0;
		}
		else {
			flag=1;n=n*10+s[i]-'0';
		}
	}
	if(!flag)printf("%s",s);
	return 0;
}