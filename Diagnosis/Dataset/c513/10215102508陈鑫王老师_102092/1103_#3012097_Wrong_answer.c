#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int ret[4]={0};
    char s[20],ch[20];
    while(scanf("%s %s",s,ch)!=EOF)
    {
        if(strcmp(s,"IN")==0)
        {
            int i;
            for(i=0;i<strlen(ch);i++)
            {
                if(ch[i]==',')break;
            }
            int ans=0,flag=1;
            i=i+1;
            if(s[i]=='-')
            {flag=-1;
            i++;
            }
            for(;i<strlen(ch);i++)
            {
                ans=ans*10+ch[i]-'0';
            }
            ret[ch[0]-'A']=ans*flag;


        }
        else if(strcmp(s,"MOV")==0)
        {
            ret[ch[0]-'A']=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"ADD")==0)
        {
            ret[ch[0]-'A']+=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"SUB")==0)
        {
            ret[ch[0]-'A']-=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"MUL")==0)
        {
            ret[ch[0]-'A']*=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"DIV")==0)
        {
            ret[ch[0]-'A']/=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"OUT")==0)
        {
             printf("%d\n",ret[ch[0]-'A']);
        }
    }
    return 0;
}
