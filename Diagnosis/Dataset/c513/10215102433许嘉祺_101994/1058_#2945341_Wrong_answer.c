#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{



    char c;//存放当前字符
    char d;//存放上一个或下一个字符(一般用于判断评论2的类型)
    char yinhao;//存放引号类型
    int instr=0;
    int incom=0;


    int type=0; //type1=//type2=/*判断评论类型

    while ((c=getchar())!=EOF)
    {
        if (instr==0 && incom==0)//如果都不是
        {
            if(c=='/')
            {
                d=getchar();

                if (d=='/')//判断是否是评论一
                {
                    type=1;
                    incom=1;
                }

                else if(d=='*')//评论二
                {
                    type=2;
                    incom=1;
                }

                else printf("%c%c",c,d);
            }

            else if(c=='"'||c=='\'')//判断是否是”“里
            {
                instr=1;
                yinhao=c;
                printf("%c",c);

            }

            else printf("%c",c);


            d=0;

        }



        else if(instr==1)//已在“”中
        {
            if (c=='"'||c=='\''&&(c==yinhao)) instr=0;
            printf("%c",c);
            d=0;//不管情况如何，反正不是情况2的结尾，将它归0
        }



        else if (incom==1)//在评论中
        {


            if (type==1&&c=='\n')//评论1以换行
            {
                printf("%c",c);
                type=0;
                incom=0;
                d=0;//不管情况如何，反正不是情况2的结尾，将它归0
            }


            else if(type==2 && (c=='*' || c=='/'))//评论二结束时可能出现的情况
            {
                if (c=='/'&&d=='*') //d是上一个字符
                    incom=0;

                else if(c=='*')//c是当前字符，判断它下一个是否结束
                {
                    d=getchar();
                    if(d=='/') incom=0;
                }

                if(c=='*'&&d=='*') //在取的过程中出现**/的情况是避c=*;d=*;然后跳掉
                    d='*';
            }

            else d=0;//不管情况如何，反正不是情况2的结尾，将它归0，如若不归0，可能使相隔很远的c,d产生交互
        }
    }


    return 0;
}