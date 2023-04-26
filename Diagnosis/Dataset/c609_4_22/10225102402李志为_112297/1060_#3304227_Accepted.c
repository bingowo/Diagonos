#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*R(char*s)
{
    if(*s){
        char t[201];
        *t=*(t+1)=*s;
        if(strcmp((strcpy(t+2,R(s+1))-2),s)<0) strcpy(s,t);
    }
    return s;
}
int main()
{
    char s[201];
    scanf("%s",s);
    printf("%s",R(s));
	return 0;
}