#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int changeit(char a);
int isdigit1(char a);
int main()
{
    int flag,flag2,i,k;
    char s[10001],*p;
    unsigned int res[10000];
    scanf("%s",s);
    p=s;
    flag=-1;        //记录有没有合法的十六进制数，默认没有，0为有合法数
    flag2=0;        //记录前导零被删掉了没有，0为没有,1为已删
    k=0;memset(res,0,sizeof(res));
    while(strstr(p,"0x")!=NULL)
    {
        p=strstr(p,"0x")+2;
        flag2=0;
        while(isdigit1(*p))
        {
            if(!flag2)
            {
                if(changeit(*p)!=0)
                {
                    flag2=1;
                    flag=0;
                }
            }
            if(flag2)
            {
                res[k]=res[k]*16+changeit(*p);
            }
            p++;
        }
        k++;
    }
    if(flag==-1)
        printf("-1");
    else
        for(i=0;i<k;i++)
        {
            printf("%d",res[i]);
        }
    return 0;
}
int changeit(char a)
{
    int num;
    if(a>='0'&&a<='9')
        num=a-'0';
    else
        num=a-'a'+10;
    return num;
}
int isdigit1(char a)
{
    if((a>='0'&&a<='9')||(a>='a'&&a<='f'))
        return 1;
    else
        return 0;
}
