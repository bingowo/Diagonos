#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[1001];
	char out[2002]={-1};
	scanf("%s",str);
	int len=strlen(str);
	out[1002]=toupper(str[0]);
	int head=1002;
	for(int l=1;l<len;l++)	{
		char c=toupper(str[l]);
		if(c>=str[head]) {
			head--;
			out[head]=c;
		}
		else out[head+l]=c;
	}
	
	
	for(int k=0;k<2002;k++){
		if(out[k]>='A'&&out[k]<'Z') printf("%c",out[k]);
	}
	
	return 0;
	}