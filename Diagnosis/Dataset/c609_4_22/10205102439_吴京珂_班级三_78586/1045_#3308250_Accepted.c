#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, temp;
    int ret1=-1, ret2=-1, ret3=-1, ret4=-1;
    while(scanf("%c",&c)!=EOF)
    {
        //注释开始
        if(ret1==-1 && ret4==-1 && c=='/' && ret2==-1 &&ret3 == -1)
        {
            scanf("%c",&temp);
            if(temp=='/')//行注释
            {
                ret2 = -1*ret2;
                continue;
            }
            else if(temp=='*')//块注释
            {
                ret3 = -1*ret3;
                continue;
            }
            else
            {
                printf("%c",c);
            }
            c=temp;//跳过读过的字符
        }

        //注释结束
        if(ret1==-1 && ret4==-1 && c=='*' && ret3==1)
        {
            scanf("%c",&temp);
            while(temp=='*' || temp=='/')
            {
                if(temp=='/')//块注释结束
                {
                    ret3=-1*ret3;
                    break;
                }
                scanf("%c", &temp);
            }
            continue;
        }

        if(c=='\'' && ret4==-1) ret1 = -1*ret1;//单引号
        if(c=='\"' && ret1==-1) ret4 = -1*ret4;//双引号
        if(ret2==1 && c=='\n')//行注释结束
        {
            ret2 = -1*ret2;
        }
        if(c=='\\' && (ret1==1 || ret4==1))
        {
            scanf("%c", &temp);
            printf("%c%c", c, temp);
            continue;
        }
        if(ret2 != 1 && ret3 != 1) printf("%c", c);

    }
    return 0;
}



