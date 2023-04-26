#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int changeit(char a);
int isdigit1(char a);
int main()
{
    int flag,flag2,i,k;
    char s[100001],*p;          //其一，一万不是10的五次方，十万才是，看0的个数
    unsigned int res[100000];
    scanf("%s",s);
    p=s;
    flag=-1;        //记录有没有合法的十六进制数，默认没有，0为有合法数
    flag2=0;        //记录前导零被删掉了没有，0为没有,1为已删
    k=-1;memset(res,0,sizeof(res));
    while(strstr(p,"0x")!=NULL)
    {
        flag2=0;
        p=strstr(p,"0x")+2;
        if(isdigit1(*p))
            k++;
        while(isdigit1(*p))
        {
            flag=0;             //找到0也算找到
            if(!flag2)
            {
                if(changeit(*p)!=0)
                {
                    flag2=1;
                }
            }
            if(flag2)
            {
                res[k]=res[k]*16+changeit(*p);
            }
            p++;
        }

    }
    if(flag==-1)
        printf("-1");
    else
        for(i=0;i<k+1;i++)
        {
            printf("%d ",res[i]);
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
