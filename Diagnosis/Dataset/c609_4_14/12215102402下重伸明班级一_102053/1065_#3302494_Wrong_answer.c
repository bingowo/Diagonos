#include<stdio.h>
#include<stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double);
double pop(void);
int main()
{
    char ming[1000];
    gets(ming);
    int shuzi[100]={};
    char fuhao[100];
    int i;  //搜索指针
    int j=strlen(ming);
    int si=0;
    int type,x;
    for(i=0;i<j;i++)
    {
        if(ming[i] <= '9' && ming[i] >= '0')
        {
            for(;(ming[i] <= '9' && ming[i] >= '0');i++)
            {
                shuzi[si]=shuzi[si]*10+(ming[i]-'0');
            }
            si++;

        }
        else
        {
            if ((ming[i]=='-')&&(ming[i+1] <= '9' && ming[i+1] >= '0'))
                {
                    i++;  // 跳过空格
                    for(;(ming[i] <= '9' && ming[i] >= '0');i++)
                    {
                        shuzi[si]=shuzi[si]*10+(ming[i]-'0');
                    }
                    shuzi[si]=shuzi[si]* -1;
                    si++;

                }
                else
                {
                    switch(ming[i])
                    {
                        case '+':
                            x=shuzi[si-2]+shuzi[si-1];
                            shuzi[si-2]=x;
                            break;
                        case '-':
                            x=shuzi[si-2]-shuzi[si-1];
                            shuzi[si-2]=x;
                            break;
                        case '*':
                            x=shuzi[si-2]*shuzi[si-1];
                            shuzi[si-2]=x;
                            break;
                        case '/':
                            x=shuzi[si-2]/shuzi[si-1];
                            shuzi[si-2]=x;
                            break;
                        case '%':
                            x=shuzi[si-2]%shuzi[si-1];
                            shuzi[si-2]=x;
                            break;
                    }
                    shuzi[si-1]=0;
                    si=si-1;
                    i++;  //qishi yinggai i+2 zhe li shewng lue
                          // 但前面是循环的关系 不能是i+si-2 跳过空格需要手动



                }



        }




    }
    printf("%d",shuzi[si-1]);  //ceshi
}
