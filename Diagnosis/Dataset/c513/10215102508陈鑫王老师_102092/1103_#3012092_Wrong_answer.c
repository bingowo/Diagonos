#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int ret[500000]={0};
    char s[20];
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"IN")==0)
        {
            scanf("%s",s);
            int i;
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]==',')break;
            }
            int ans=0;
            for(i=i+1;i<strlen(s);i++)
            {
                ans=ans*10+s[i]-'0';
            }
            ret[s[0]-'A']=ans;


        }
        else if(strcmp(s,"MOV")==0)
        {
            scanf("%s",s);
            ret[s[0]-'A']=ret[s[3]-'A'];
        }
        else if(strcmp(s,"ADD")==0)
        {
             scanf("%s",s);
            ret[s[0]-'A']+=ret[s[3]-'A'];
        }
        else if(strcmp(s,"SUB")==0)
        {
             scanf("%s",s);
            ret[s[0]-'A']-=ret[s[3]-'A'];
        }
        else if(strcmp(s,"MUL")==0)
        {
            ret[s[0]-'A']*=ret[s[3]-'A'];
        }
        else if(strcmp(s,"DIV")==0)
        {
             scanf("%s",s);
            ret[s[0]-'A']/=ret[s[3]-'A'];
        }
        else
        {
             scanf("%s",s);
             printf("%d\n",ret[s[0]-'A']);
        }
    }
    return 0;
}
