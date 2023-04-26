#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[105];
	int max=0;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='1'&&s[i]<='9'){
			int len=1,j=i+1;
			while(s[j]>='0'&&s[j]<='9'&&j<strlen(s)){
				len++;
				j++;
			}
			if(len>max){
				max=len;
			}
		}
	}
	printf("%d",max);
    return 0;
}