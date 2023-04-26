#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	    char s[10001];
	    scanf("%s",s);
	    char *p=s;
	    for(;*p!='\0';p++){
	    	char si[10001];
	    	char*p2=si;
	    	int num=0,i,len=0;
	    	while(*p>='a'&&*p<='z'){
				*p2=*p;
				p2++;
				p++;
			}
			*p2='\0';
			if(*p>='0'&&*p<='9'){
				while(*p>='0'&&*p<='9')
				{
				num=num*10+*p-'0';
				p++;
				}
				p--;	
			}
			if(*p=='\0'){
				num=1;
			}
			for(i=0;i<num;i++) printf("%s",si);
		}
		return 0;
}