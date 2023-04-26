#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void doint(int n);
void dodouble(double d);
int main()
{
    char s[31];
    while(scanf("%s",s) != EOF)
    {
        if(strchr(s,'.') == 0)
            doint(atoi(s));
        else
            dodouble(atof(s));
    }

    return 0;
}
void doint(int n)
{
	int c = sizeof(n);
	unsigned char* p = (unsigned char*)&n;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
} 
void dodouble(double d)
{
	int c = sizeof(d);
	unsigned char* p = (unsigned char*)&d;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
} 