#include <stdio.h>
#include <string.h>

int main()
{
    char s[40]={0};
    long long ans[100];
    while(gets(s))
    {
        int pos;
        for(pos=0;s[pos]!=' ';pos++);
        pos++;
        if(s[0]=='I')
        {
            int flag=1;
            int val=pos+3;
            int num=0;
            if(s[val]=='-') //注意负号！
            {
                val++;
                flag=-1;
            }
            for(;s[val]!='\0';val++)
            {
                num=num*10+s[val]-'0';
            }
            ans[s[pos]]=num*flag;
        }
        else if(s[0]=='M' && s[1]=='O')
        {
            ans[s[pos]]=ans[s[pos+3]];
        }
        else if(s[0]=='A')
        {
            ans[s[pos]]+=ans[s[pos+3]];
        }
        else if(s[0]=='S')
        {
            ans[s[pos]]-=ans[s[pos+3]];
        }
        else if(s[0]=='M')
        {
            ans[s[pos]]*=ans[s[pos+3]];
        }
        else if(s[0]=='D')
        {
            ans[s[pos]]/=ans[s[pos+3]];
        }
        else if(s[0]=='O')
        {
            printf("%lld\n",ans[s[pos]]);
        }
    }
}
