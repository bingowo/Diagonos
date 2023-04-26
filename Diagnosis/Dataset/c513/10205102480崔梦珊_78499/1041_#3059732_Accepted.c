#include<stdio.h>
#include<string.h>
int main()
{
    int ans=1;
    int tem=0;
    char s[51];
    char c;
    char temp='1';
    while((c=getchar())!='\n')
    {
        if(c!=temp)
        {
            tem++;
        }
        else
        {
            if(tem>ans)  ans=tem;
            tem=1;
        }
        temp=c;
    }
    if(tem>ans)  ans=tem;
    printf("%d",ans);
}
