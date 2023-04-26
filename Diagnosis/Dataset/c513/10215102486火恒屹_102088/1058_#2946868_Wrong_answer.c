#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int strflag=0;
    int delflag=0;
    while((c=getchar())!=EOF)
    {
        if(((c!='/')&&(c!='"')&&(delflag==0))||(strflag==1))   //正常的代码或是在字符串中
            printf("%c",c);
        else if((strflag==0)&&(delflag==0)&&(c=='/')) //注释的开始
        {
            char d=getchar();
            if(d=='/')
                delflag=1;
            else if(d=='*')
                delflag=2;
            else
                printf("%c%c",c,d);
        }
        else if((strflag==0)&&(delflag==1)&&(c==10)) //行注释的结束
        {
            delflag=0;
            printf("%c",10);
        }
        else if((strflag==0)&&(delflag==2)&&(c=='*')) //段注释的结束
        {
            char d=getchar();
            if(d=='/')
                delflag=0;
            else
                ungetc(d,stdin);
        }
        else if((delflag==0)&&(c='"')&&(strflag==0)) //字符串的开始
        {
            strflag=1;
            printf("%c",c);
        }
        else if((delflag==0)&&(c='"')&&(strflag==1)) //字符串的结束
        {
            strflag=0;
            printf("%c",c);
        }
    }
    return 0;
}
