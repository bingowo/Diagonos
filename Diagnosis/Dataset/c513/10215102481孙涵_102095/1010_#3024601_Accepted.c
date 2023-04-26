#include <stdio.h>
#include <string.h>

char* bin(unsigned int N) {
	static char buf[11];
    int k = 9;
    do
    {
        buf[k--] = N % 2 + '0';
        N = N / 2;
    } while (N || k >= 0);
    return buf;
}


int main() {
	char s[1000];
	char output[5000];
	gets(s);
	char *p = output;
	int i = 0, l = strlen(s);
	for(;i + 2 < l; i += 3) {
		unsigned int triple = (s[i]-'0') * 100 + 
							  (s[i+1]-'0') * 10 +
							  (s[i+2]-'0');
		strcpy(p, bin(triple));
		p += 10;
	}
	if(l - i == 1) {
		unsigned int triple = (s[i]-'0'); 
		strcpy(p, bin(triple) + 6);
		p += 4;
	} else if(l - i == 2) {
		unsigned int triple = (s[i]-'0') * 10 +  (s[i+1]-'0');
		strcpy(p, bin(triple) + 3);
		p += 7;
	}
	*p = '\0';
	printf("0001%s%s\n", bin(l), output);
    return 0;
}