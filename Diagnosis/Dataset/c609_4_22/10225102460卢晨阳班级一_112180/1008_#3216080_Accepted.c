#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void outi(int n){
	int m=sizeof(n);
	unsigned char* p=(unsigned char*)&n;
	while(m--)
		printf("%02x ",*p++);
	printf("\n");
}

void outd(double q){
	int m=sizeof(q);
	unsigned char* p=(unsigned char*)&q;
	while(m--)
		printf("%02x ",*p++);
	printf("\n");
}

int main()
{
	char s[100];
	while(scanf("%s",s)!=-1){
		if(strchr(s,'.')==0)
			outi(atoi(s));
		else
			outd(atof(s));
	}
	return 0;
}