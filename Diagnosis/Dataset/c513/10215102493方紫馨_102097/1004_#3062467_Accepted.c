#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void Int(int n){
	int c = sizeof(n);
	unsigned char*p=(unsigned char*)&n;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
}
void Double(double n){
	int c = sizeof(n);
	unsigned char*p=(unsigned char*)&n;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
}

int main()
{
	char s[100];
	while(scanf("%s",s)!=EOF){
		if(strchr(s,'.')==0)
			Int(atoi(s));
		else
			Double(atof(s));
	}
	
	return 0;
}