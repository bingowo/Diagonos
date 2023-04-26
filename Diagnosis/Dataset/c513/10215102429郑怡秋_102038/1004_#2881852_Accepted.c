#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
void solveint(int n)
{
	int c=sizeof(n);
	unsigned char* p = (unsigned char*)&n;
	while(c--) printf("%02x ",*p++);
	printf("\n");
}
void solvedouble(double d){
	int c=sizeof(d);
	unsigned char*p=(unsigned char*)&d;
	while(c--) printf("%02x ",*p++);
	printf("\n");
}
int main()
{
	char s[31];
	while(scanf("%s",s)!=EOF)
	{
		int i=0,k=0;
		while(s[i]) if(s[i++]=='.') k=1;
		if(k==0) solveint(atoi(s));
		else solvedouble(atof(s));
	}
	return 0;
}