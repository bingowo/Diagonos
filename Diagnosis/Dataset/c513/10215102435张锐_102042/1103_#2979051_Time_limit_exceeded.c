#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x[26]={0};
    char temp[1000];
    while(scanf("%s",temp))
    {
        char s[15];
        scanf("%s",s);
        int len=strlen(s);
        if(strcmp(temp,"IN")==0)//ax,number->ax=number
        {
            int b=1,i=3;char c=s[0];
            if(s[3]=='-') {b=-1;i=4;}
            int num=0;
            while(i<len) num=num*10+s[i++]-'0';
            x[c-'A']=b*num;
        }
        else if(strcmp(temp,"OUT")==0)//输出ax
        {
            char c=s[0];
            printf("%d\n",x[c-'A']);
        }
        else if(strcmp(temp,"MOV")==0)//ax=bx
        {
            char a=s[0],b=s[3];
            x[a-'A']=x[b-'A'];
        }
        else if(strcmp(temp,"XCHG")==0)//交换ax和bx的值
        {
            char a=s[0],b=s[3];
            int t=x[a-'A'];x[a-'A']=x[b-'A'];x[b-'A']=t;
        }
        else if(strcmp(temp,"ADD")==0)//ax=ax+bx   ax=bx+cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']+x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[c-'A']+x[b-'A'];
            }
        }
        else if(strcmp(temp,"SUB")==0)//ax=ax-bx   ax=bx-cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']-x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']-x[c-'A'];
            }
        }
        else if(strcmp(temp,"MUL")==0)//ax=ax*bx  ax=bx*cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']*x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[c-'A']*x[b-'A'];
            }
        }
        else if(strcmp(temp,"DIV")==0)//ax=ax/bx  ax=bx/cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']/x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']/x[c-'A'];
            }
        }
        else if(strcmp(temp,"MOD")==0)//ax=ax%bx   ax=bx%cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']%x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']%x[c-'A'];
            }
        }
        else if(strcmp(temp,"AND")==0)//AX=AX&BX   ax=bx&cx
        {
            if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']&x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']&x[c-'A'];
            }
        }
        else if(strcmp(temp,"OR")==0)//AX=AX|BX   ax=bx|cx
        {
             if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']|x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']|x[c-'A'];
            }
        }
        else if(strcmp(temp,"XOR")==0)//AX=AX^BX   ax=bx^bx
        {
             if(len==5)
            {
                char a=s[0],b=s[3];
                x[a-'A']=x[a-'A']^x[b-'A'];
            }
            else
            {
                char a=s[0],b=s[3],c=s[6];
                x[a-'A']=x[b-'A']^x[c-'A'];
            }
        }
    }
    return 0;
}
