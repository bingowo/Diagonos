#include <stdio.h>
#include <string.h>

int main()
{
    char s[40]={0};
    int ans[100];
    //数组一定要初始化为0
    //不然不同的编译器可能产生错误
    ans['A']=0;
    ans['B']=0;
    ans['C']=0;
    ans['D']=0;
    
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
            printf("%d\n",ans[s[pos]]);
        }
    }
}
//首先，字母代替数字进行数组的表示，这种方式要掌握
//吸取数组初始化的教训，一定要初始化
