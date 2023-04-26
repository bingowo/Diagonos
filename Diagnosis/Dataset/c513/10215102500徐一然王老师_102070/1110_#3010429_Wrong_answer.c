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
        if(isdigit(*p))
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
        if(isdigit(*p))
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
            copy=0;
        }
        p++;

    }
    ans=(double)beichushu*(-1)/xishu;
    printf("a=%.3lf\n",ans);
}
