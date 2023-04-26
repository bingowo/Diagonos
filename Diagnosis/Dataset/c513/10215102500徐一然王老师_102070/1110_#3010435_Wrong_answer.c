#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char S[100];
    scanf("%s",S);
    int copy=0;
    int xishu=0,beichushu=0;
    int flag=1;
    char *p=S;
    char c;
    while(*p)
    {
        if(*p!='+'&&*p!='-'&&*p!='='&&(*p<='0'||*p>='9')){c=*p;break;}
        p++;
    }
    p=S;
    double ans=0;
    while(*p)
    {
        if(*p=='=')
        {p++;flag=-1;
            while(*p)
            {
                if(*p=='+')
        {
            flag=-1;
        }
        if(*p=='-')
        {
            flag=1;
        }
        if(isdigit(*p)||*p==c)
        {
            while(isdigit(*p)&&*p)
            {
                copy=copy*10+*p-'0';p++;
            }
            if(*p!='+'&&*p!='-'&&*p!='='&&*p!='\0')
            {
                xishu=xishu+copy*flag;
            }
            else
            {
                beichushu=beichushu+copy*flag;p--;
            }
            if(xishu==0)xishu=1*flag;
            copy=0;
        }
        p++;
            }
        }
        if(*p=='+')
        {
            flag=1;
        }
        if(*p=='-')
        {
            flag=-1;
        }
        if(isdigit(*p)||*p==c)
        {
            while(isdigit(*p))
            {
                copy=copy*10+*p-'0';p++;
            }
            if(*p!='+'&&*p!='-'&&*p!='=')
            {
                xishu=xishu+copy*flag;
            }
            else
            {
                beichushu=beichushu+copy*flag;p--;
            }
            if(xishu==0)xishu=1*flag;
            //printf("%d",xishu);
            copy=0;
        }
        p++;

    }
    //printf("%d %d\n",xishu,beichushu);
    if(xishu==0)
    {
        printf("%c=%.3lf\n",c,ans);
    }
    else
    {
        ans=(double)beichushu*(-1)/xishu;
    printf("%c=%.3lf\n",c,ans);
    }

}
