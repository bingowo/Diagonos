#include <stdio.h>

int main()
{
    /*先把所有状态枚举出来，从简单到复杂依次为：
    1.位于双斜杠之间的行，全部不输出
    2.位于*+/之间的行，全部不输出
    3.如果与引号相关，有可能会出现引号里出现引号，但是这个时候会有\出现在单引号前面
    4.处于引号中，是最优级别，如果在双引号之内，则全部作废不输出*/
    int sy = 0;
    char c,tmp;
    while((c = getchar()) != EOF)
    {
        if(c == '\\'){
            tmp = getchar();
            printf("%c%c",c,tmp);
        }
        else if(c == '\"'){
            printf("%c",c);
            if(sy == 0) sy = 1;
            else sy = 0;
        }
        else if(c == '/' && sy == 0){
            tmp = getchar();
            if(tmp == '/'){
                while(1)
                {
                    c = getchar();
                    if(c == '\n') {
                        printf("\n");
                        break;
                    }
                }
            }
            else if(tmp == '*'){
                int a=0,b=0;           //记录状态
                while(1)
                {
                    if(a+b == 2) break;
                    c = getchar();
                    if(c == '*'){
                        a = 1;
                        c = getchar();
                        if(c == '/') b = 1;
                        else if(c == '*') a = 1;
                        else a = 0;
                    }
                    if(c == '/' && a == 1) b = 1;
                }
            }
            else {
                printf("%c%c",c,tmp);
            }
        }
        else printf("%c",c);
    }
    return 0;
}