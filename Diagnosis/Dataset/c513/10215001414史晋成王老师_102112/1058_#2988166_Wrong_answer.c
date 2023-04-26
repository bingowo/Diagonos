#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void echo_quote(char c)
{
    char d;putchar(c);
    while((d=getchar())!=c)
    {
        if(d==EOF)return;
        putchar(d);
        if(d=='\\')
            putchar(getchar());
    }
    putchar(d);
}

void in_comment()
{
    char c,d;
    c=getchar();
    if(c==EOF)return;
    d=getchar();
    if(d==EOF)return;
    while(c!='*'||d!='/')
    {
        c=d;d=getchar();
        if(d==EOF)return;
    }
}

void start_comment()
{
    char c,d;
    while(c!='\n')
    {
        c=getchar();
        if(c==EOF)return;
    }putchar(c);
}

void recomment(char c)
{
    char d;
    if(c=='/')
    {
        if((d=getchar())=='*')
        {
            in_comment();
        }
        else if(d=='/')
            start_comment();
        else{putchar(c);putchar(d);}
    }
    else
        putchar(c);
}

int main()
{
    char c,d;
    while((c=getchar())!=EOF)
        recomment(c);
}
