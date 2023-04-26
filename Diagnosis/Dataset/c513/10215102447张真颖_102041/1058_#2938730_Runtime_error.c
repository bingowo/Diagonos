#include <stdio.h>
#include <stdlib.h>
void state1();
void state2();
void state3();
void state4();
void state5();
void state6();

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
            printf("/%c",ch);
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
            state5();
        }
        else
        {
            printf("%c",ch);
            state4();
        }
    }
    return;
}
void state5()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='/') state6();
        else if(ch=='\n') printf('\n'),state0();
        else printf("%c",ch),state5();
    }
    return;
}
void state6()
{
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='/'||ch=='*') state1();
        else printf("%c",ch),state4();
    }
    return;
}

int main()
{
    state0();
    return 0;
}