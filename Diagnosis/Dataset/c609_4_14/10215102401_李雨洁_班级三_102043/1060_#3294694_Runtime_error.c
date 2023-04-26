#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* R(char* s)
{
    if(*s)
    {
        char t[201];
        *t=*(t+1)=*s;//s第一个字母的复制
        if(strcmp(strcpy(t+2,R(s+1))-2,s)<0)//字典排序
        {
            strcpy(s,t);
        }
    }
    return s;
}

int main()
{
    char s[101];
    scanf("%s",s);
    printf("%s\n",R(s));
    return 0;
}
