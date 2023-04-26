#include <stdio.h>
#include <stdlib.h>

/*
初始 s=0;
    接收到普通字符 s=0;
    接收到/ s=1;
        接收到* s=2;接收到* s=3，接收到非* s=2;接收到* s=3，接收到/ s=0,接收到非/ s=2;
        接收到/ s=4;接收到\n s=0;
    接收到" s=5;接收到" s=0;
                接收到\，s=6;接收下一个字符，s=5;
    接收到' s=7;接收到' s=0;

*/

int main()
{
    char c;int state=0;
    char ans[5000]={0};int p=0;
    while((c=getchar())!=EOF)
    {
        switch(state)
        {
            case 0:
                if(c=='/')
                {
                    state=1;
                }
                else if(c=='"')
                {
                    state=5;
                    ans[p++]=c;
                }
                else if(c=='\'')
                {
                    state=7;
                    ans[p++]=c;
                }
                else
                {
                    state=0;
                    ans[p++]=c;
                }
                break;
            case 1:
                if(c=='*')state=2;
                else if(c=='/')state=4;
                else
                {
                    state=0;
                    ans[p++]='/';
                    ans[p++]=c;
                }
                break;
            case 2:
                if(c=='*')state=3;
                break;
            case 3:
                if(c=='/')state=0;
                else if(c=='*')state=3;
                else state=2;
                break;
            case 4:
                if(c=='\n')
                {
                    state=0;
                    ans[p++]=c;
                }
                break;
            case 5:
                ans[p++]=c;
                if(c=='"')state=0;
                else if(c=='\\')state=6;
                break;
            case 6:
                ans[p++]=c;
                state=5;
                break;
            case 7:
                ans[p++]=c;
                if(c=='\'')state=0;
                break;
        }
    }
    ans[p++]='\0';
    printf("%s",ans);
    return 0;
}
