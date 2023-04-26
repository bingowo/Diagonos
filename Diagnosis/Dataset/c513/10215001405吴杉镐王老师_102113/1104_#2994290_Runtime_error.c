#include <stdio.h>
#include <string.h>

int main()
{
    char s[40]={0};
    int ans[100];
    //数组一定要初始化为0
    //不然不同的编译器可能产生错误
    for(int i='A';i<='Z';i++)
    {
        ans[i]=0;
    }
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
                num=num*10+s[val]-'0';
            ans[s[pos]]=num*flag;
            //printf("%d\n",ans[s[pos]]);
        }
        else if(s[0]=='M' && s[1]=='O' && s[2]=='V')
            ans[s[pos]]=ans[s[pos+3]];
        else if(s[0]=='O' && s[1]=='U')
            printf("%d\n",ans[s[pos]]);
        else if(s[0]=='X' && s[1]=='C')
        {
            int m=ans[s[pos]];
            ans[s[pos]]=ans[s[pos+3]];
            ans[s[pos]+3]=m;
        }
        else if(s[9]!='\0') //三参数
        {
            if(s[0]=='A' && s[1]=='D')
            {
                ans[s[pos]]=ans[s[pos+3]]+ans[s[pos+6]];
            }
            else if(s[0]=='S')
            {
                ans[s[pos]]=ans[s[pos+3]]-ans[s[pos+6]];
            }
            else if(s[0]=='M' && s[1]=='U')
            {
                ans[s[pos]]=ans[s[pos+3]]*ans[s[pos+6]];
            }
            else if(s[0]=='D')
            {
                ans[s[pos]]=ans[s[pos+3]]/ans[s[pos+6]];
            }
            else if(s[0]=='M')
            {
                ans[s[pos]]=ans[s[pos+3]]%ans[s[pos+6]];
            }
            else if(s[0]=='A')
            {
                ans[s[pos]]=ans[s[pos+3]]&ans[s[pos+6]];
            }
            else if(s[0]=='O')
            {
                ans[s[pos]]=ans[s[pos+3]]|ans[s[pos+6]];
            }
            else if(s[0]=='X')
            {
                ans[s[pos]]=ans[s[pos+3]]^ans[s[pos+6]];
            }
        }
        else
        {
            if(s[0]=='A' && s[1]=='D')
            {
                ans[s[pos]]+=ans[s[pos+3]];
            }
            else if(s[0]=='S')
            {
                ans[s[pos]]-=ans[s[pos+3]];
            }
            else if(s[0]=='M' && s[1]=='U')
            {
                ans[s[pos]]*=ans[s[pos+3]];
            }
            else if(s[0]=='D')
            {
                ans[s[pos]]/=ans[s[pos+3]];
            }
            else if(s[0]=='M')
            {
                ans[s[pos]]%=ans[s[pos+3]];
            }
            else if(s[0]=='A')
            {
                ans[s[pos]]&=ans[s[pos+3]];
            }
            else if(s[0]=='O')
            {
                ans[s[pos]]|=ans[s[pos+3]];
            }
            else if(s[0]=='X')
            {
                ans[s[pos]]^=ans[s[pos+3]];
            }
        }
    }
}

