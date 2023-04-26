#include<stdio.h>

void recomment(int c);
void in_comment(void);
void echo_quote(int c);
void start_comment();


int main()
{
    int c, d;
    while ((c = getchar()) != EOF)
    {
        recomment(c);
    }
    return 0;
}

//搜索注释的开始位置
void recomment(int c)
{
    int d;
    if (c == '/')
    {
        if ((d = getchar()) == '*')
        {
            in_comment();
        }
        else if (d == '/')
        {
            start_comment();
        }
        else
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')
    {
        echo_quote(c);
    }
    else
    {
        putchar(c);
    }
}


//删除以"//"开始的注释
void start_comment()
{
    int c, d;
    while ((c = getchar()) != '\n')
        ;
    putchar(c);
}

//删除"/*    */"注释 
void in_comment()
{
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

//保证引号里面的内容可以完整输出
void echo_quote(int c)
{
    int d;
    putchar(c);
    while ((d = getchar()) != c)
    {
        putchar(d);
        if (d == '\\')
        {
            putchar(getchar());
        }
    }
    putchar(d);
}
————————————————
版权声明：本文为CSDN博主「sty945」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/sty945/article/details/82924731