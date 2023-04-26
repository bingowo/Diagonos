#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main()
{
	
	char s[10001];
	scanf("%s",s);
	char str[10001]={0},num[4]={0};
	int a=0,b=0,sign=0,n;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(sign==0){
				str[a]='\0';
			}
			num[b++]=s[i];
			sign=1;
		}else{
			if(sign==1){
				num[b]='\0';
				n=atoi(num);
				while(n--){
					printf("%s",str);
				}
				a=0,b=0;
				memset(str,0,sizeof(s));
				memset(num,0,sizeof(num));
			}
			str[a++]=s[i];
			sign=0;
		}
	}
	if(sign==1){
		num[b]='\0';
		n=atoi(num);
		while(n--){
			printf("%s",str);
		}
	}
	if(sign==0){
		str[a]='\0';
		printf("%s",str);
	}
	return 0;
 } 