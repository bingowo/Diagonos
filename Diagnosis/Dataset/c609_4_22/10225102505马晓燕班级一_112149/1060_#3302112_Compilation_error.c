#include <stdio.h>
#include <string.h>
#define N 100
char* R(char* s)
{
    if(*s!=0)//未结束是否为空串
    {
        char t[2*N+1]
        if(strcmp((*t=*(t+1)=*s,strcpy(t+2,R(s+1))-2),s)<0)
            strcpy(s,t);
    }
    return s;
}

int main()
{
    char s[2*N+1];
    scanf("%s",s);
    printf("%s\n",R(s));
    return 0;
}