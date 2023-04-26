#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mid(char* s,int a,int b)
{
    if (b-a==1)
        return 0;
    else if (s[a+1]=='(' && s[b-1]==')')
        return small(s,a+1,b-1);
    else return 0;
}

int large(char* s,int a,int b)
{
    if (b-a==1)
        return 0;
    else if (s[a+1]=='[' && s[b-1]==']')
        return mid(s,a+1,b-1);
    else return 0;
}

int small(char* s,int a,int b)
{
    if (b-a==1)
        return 1;
    else if (s[a+1]=='{' && s[b-1]=='}')
        return large(s,a+1,b-1);
    else return 0;
}

int result(char* s)
{
    if (s[0]=='{' && s[strlen(s)-1]=='}')
        return large(s,0,strlen(s)-1);
    if (s[0]=='(' && s[strlen(s)-1]==')')
        return small(s,0,strlen(s)-1);
    if (s[0]=='[' && s[strlen(s)-1]==']')
        return mid(s,0,strlen(s)-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char s[120]={0};
        scanf("%s",s);
        printf("%s\n",result(s)?"Yes":"No");

    }
    return 0;
}
