#include<stdio.h>
#include<string.h>

#define N 100

char*R(char*s)
{
    if(*s)
    {
        char t[2*N+1];
        if(strcmp((*t=*(t+1)=*s,strcpy(t+2,R(s+1))-2),s)<0) strcpy(s,t);
    }
    return s;
}

int main()
{
    char s[2*N+1];
    printf("%s\n",(scanf("%s",s),R(s)));

    return 0;
}