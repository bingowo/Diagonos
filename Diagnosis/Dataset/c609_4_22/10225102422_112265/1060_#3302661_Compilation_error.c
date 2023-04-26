#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
char* R(char* s)
{
    char t[2*N+1];
    if(*s)
    {
        if(strcmp((*t=*(t+1)=*s,strcpy(t+2,R(s+1))-2),s)<0)
        strcpy(s,t);
    }
}
int main()
{
	char s[2*N + 1];
	fgets(s,2*N + 1,stdin);
	if (s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] == 0;
	R(s);
		printf("%s\n", s);
	}
	return 0;
}