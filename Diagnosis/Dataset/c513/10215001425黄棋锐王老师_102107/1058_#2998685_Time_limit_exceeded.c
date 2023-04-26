#include<stdio.h>

void recomment(char c);
void in_comment();
void echo_quote(char c);
void start_comment();


int main()
{
    char c, d;
    while ((c = getchar()) != EOF)
    {
        recomment(c);
    }
    return 0;
}

//搜索注释的开始位置
void recomment(char c)
{
    char d;
    if (c == '/')//判断是否有注释出现 
    {
        if ((d = getchar()) == '*')
        {
            in_comment();
        }
        else if (d == '/')
        {
            start_comment();
        }
        else//无注释，斜杆为字符 
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')//引号 
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
    char c, d;
    for (;(c = getchar()) != '\n';);
    putchar(c);
}

//删除"/*    */"注释 
void in_comment()
{
    char c, d;
    c = getchar();
    d = getchar();
    while (!(c == '*' && d == '/'))
    {
        c = d;
        d = getchar();
    }
}

//保证引号里面的内容可以完整输出
void echo_quote(char c)
{
    char d;
    putchar(c);
    while ((d = getchar()) != c)
    {
        putchar(d);
        if (d == '\\')//换行连接符，类似英语作文末尾两段的连接符 
        {
            putchar(getchar());
        }
    }
    putchar(d);
}