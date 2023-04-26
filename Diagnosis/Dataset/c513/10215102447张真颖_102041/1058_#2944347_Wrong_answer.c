#include <stdio.h>
#include <stdlib.h>
void state1();
void state2();
void state3();
void state4();

void state0()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='/') state1();
        else if(ch=='"') printf("%c",ch),state4();
        else printf("%c",ch);
    }
    return;
}
void state1()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='*') state2();
        else if(ch=='/')
        {
            while((ch=getchar())!=EOF&&ch!='\n') ;
            printf("\n");
            state0();
        }
        else
        {
            printf("%c",ch);
            state0();
        }
    }
    return ;
}
void state2()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='*') state3();
        else state2();
    }
    return;
}
void state3()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='*') state3();
        else if(ch=='/') state0();
        else state2();
    }
}
void state4()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='"')
        {
            printf("%c",ch);
            state0();
        }
        else if(ch=='\\')
        {
            printf("%c",ch);
            ch=getchar();
            printf("%c",ch);
        }
        else
        {
            printf("%c",ch);
            state4();
        }
    }
    return;
}

int main()
{
    state0();
    return 0;
}