#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int ret[4]={0};
    char s[20];
    while(scanf("%s",s)!=EOF)
    {
        char ch[20];
        if(strcmp(s,"IN")==0)
        {
            scanf("%s",ch);
            int i;
            for(i=0;i<strlen(ch);i++)
            {
                if(ch[i]==',')break;
            }
            int ans=0;
            for(i=i+1;i<strlen(ch);i++)
            {
                ans=ans*10+ch[i]-'0';
            }
            ret[ch[0]-'A']=ans;


        }
        else if(strcmp(s,"MOV")==0)
        {
            scanf("%s",ch);
            ret[ch[0]-'A']=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"ADD")==0)
        {
             scanf("%s",ch);
            ret[ch[0]-'A']+=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"SUB")==0)
        {
             scanf("%s",ch);
            ret[ch[0]-'A']-=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"MUL")==0)
        {
            scanf("%s",ch);
            ret[ch[0]-'A']*=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"DIV")==0)
        {
             scanf("%s",ch);
            ret[ch[0]-'A']/=ret[ch[3]-'A'];
        }
        else if(strcmp(s,"OUT")==0)
        {
             scanf("%s",ch);
             printf("%d\n",ret[ch[0]-'A']);
        }
    }
    return 0;
}
