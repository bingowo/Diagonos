#include <stdio.h>
#include <stdlib.h>



long long po = 0;
void push(char *p,char c)
{
    p[po++] = c;
    return ;
}
char out(char *p)
{
if(po>0)return p[--po];
else return EOF;
}

int main()
{
    char c;
     int flag1 = 1;// 关于//
        int flag2 = 1;//关于*/
        int flag3 = 1;//关于“”
        int flag4 = 0;//辅助判断*/
        int flag5 = 0;//辅助判断“”
        char *sta = (char*)malloc(sizeof(char)*1e8);

    while((c=getchar())!=EOF)
    {

        if(flag3)
        {
            if(flag2)
            {
                if(flag1)
                    {
                        switch(c)
                        {
                        case '"':
                            {
                                push(sta,c);
                                flag3 = 0;
                                break;
                            }
                        case '/':
                            {
                                push(sta,c);
                                c=getchar();
                                if(c=='/')
                                {
                                    flag1=0;
                                    out(sta);
                                }
                                else if(c=='*')
                                {
                                    flag2 = 0;
                                    out(sta);

                                }
                                else continue;
                                break;
                            }
                        default:
                            {
                                push(sta,c);
                            }
                        }

                    }
                    else
                {
                    if(c=='\n')
                    {
                        push(sta,c);
                        flag1=1;
                    }
                }
            }
            else
            {
                if(c=='*')
                {
                   flag4= 1;
                }

                else if(flag4&&c=='/')
                {
                    flag2=1;
                    flag4=0;
                }
                else flag4=0;
            }
        }
        else
        {
            push(sta,c);
            if(c=='"'&&c[po-1]!='\\')flag3 =1;
        }

    }
    for(long long i=0;i<po;i++)
    {
        printf("%c",sta[i]);
    }

    free(sta);
    return 0;
}
