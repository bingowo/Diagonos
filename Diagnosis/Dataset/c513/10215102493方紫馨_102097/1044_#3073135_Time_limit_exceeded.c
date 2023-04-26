#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned int trans(char s[],int a){
	unsigned int ret=0,r;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9')
			r=s[i]-'0';
		else
			r=s[i]-'a'+10;
		ret=ret*16+r;
	}
	return ret;
}

int main()
{
	char s[100001];
	scanf("%s",s);
	char hex[20];
	int sign=0,a=0,is=0;
	for(int i=0;i<strlen(s);i++){
		if(sign==0&&s[i]=='0'){
			sign=1;continue;
		}
		if(sign==1&&s[i]=='x'){
			sign=2;continue;
		}
		if(sign==2)
		{
			
			if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')){
				hex[a++]=s[i];
				is=1;
			}
				
			else{
				if(a!=0){
					hex[a]='\0';					
					printf("%u ",trans(hex,a));
					a=0;
				}
				sign=0;			 			
			}
		}
	}
	if(sign==2&&a!=0){
		printf("%u ",trans(hex,a));
	}
	if(is==0)
		printf("-1");
	
	return 0;
 } 