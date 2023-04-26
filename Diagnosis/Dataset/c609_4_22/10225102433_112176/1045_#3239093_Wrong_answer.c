#include <stdio.h>
#include <string.h>

int main()
{
    int s1 = -1,s2 = -1,s3 = -1;           //分别用来检测双引号，行注释，块注释
    char c,tmp;
    while((c = getchar()) != EOF)
    {
        if(c == '\"') s1 = -s1;           //如果s1是-1那么说明没有双引号制约，否则存在双引号制约
        if(c == '/' && s1 == -1){
            tmp = getchar();
            if(tmp == '/'){              //进入行注释
                while(1){
                    c = getchar();
                    if(c == '\n'){
                        break;
                    }
                }
            }
            else if(tmp == '*'){         //进入块注释
                char s[3] = {0};
                char c1,c2;
                c1 = getchar();
                c2 = getchar();
                s[0] = c1;s[1] = c2;
                while(strcmp(s,"*/") != 0){
                    s[0] = s[1];
                    char res = getchar();
                    s[1] = res;
                }
                continue;
            }
        }
        putchar(c);
    }
    return 0;
}