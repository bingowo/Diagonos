#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(int num,char *p){
	int ys;
	while(num){
		ys=num%2;
		*p=ys+'0';
		p++;
		num=num/2;
	}
	*p='\0';
}
void rever(char a[]){
	for(int i=0,j=strlen(a)-1;i<j;i++,j--){
		char c=a[i];
		a[i]=a[j];
		a[j]=c;
	}
}
int main()
{
    char s[505];
    gets(s);
    char second[12];
    char first[5]={"0001"};
	trans(strlen(s),second);
	for(int i=strlen(second);i<10;i++){
		second[i]='0';
	}
	second[10]='\0';
	rever(second);
	printf("%s%s",first,second);
    for(int i=0;i<strlen(s)-2;i=i+3){
    	char si[11];
    	int ni=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    	trans(ni,si);
    	for(int i=strlen(si);i<10;i++){
			si[i]='0';
		}
		si[10]='\0';
		rever(si);
		printf("%s",si);
	}
	if(strlen(s)%3==2){
		char si[8];
		int ni=(s[strlen(s)-2]-'0')*10+(s[strlen(s)-1]-'0');
    	trans(ni,si);
    	for(int i=strlen(si);i<7;i++){
			si[i]='0';
		}
		si[7]='\0';
		rever(si);
		printf("%s",si);
	}
	else if(strlen(s)%3==1)
	{
		char si[5];
		int ni=s[strlen(s)-1]-'0';
		trans(ni,si);
		for(int i=strlen(si),i<4;i++){
			si[i]='0';
		}
		s[4]='\0';
		rever(si);
		printf("%s",si);
	}
    return 0;
}