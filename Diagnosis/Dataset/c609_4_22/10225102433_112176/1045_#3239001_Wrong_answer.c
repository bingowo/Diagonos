#include <stdio.h>
#include <string.h>

int main()
{
    int s1 = -1,s2 = -1,s3 = -1;           //分别用来检测双引号，行注释，块注释
    char c,tmp;
    while((c = getchar()) != EOF)
    {
        if(c == '\"') s1 = -s1;           //如果s1是-1那么说明没有双引号制约，否则存在双引号制约
        if(c == '/' && s1 == 1){
            tmp = getchar();
            if(tmp == '/'){              //进入行注释
                while(1){
                    c = getchar();
                    if(c == '\n') printf("\n");
                    break;
                }
            }
            else if(tmp == '*'){         //进入块注释
                while(1){
                    c = getchar();
                    if(c == '*'){
                        tmp = getchar();
                        if(tmp == '/'){
                            break;
                        }
                    }
                }
            }
        }
    }
    putchar(c);
    return 0;
}