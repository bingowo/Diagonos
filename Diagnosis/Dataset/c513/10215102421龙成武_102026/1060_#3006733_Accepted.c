#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int lens,i,ans,temp;
    char s[101];
    scanf("%s",s);
    lens=strlen(s);
    temp=ans=0;
    for(i=0;i<lens;i++)
    {
        if(isdigit(s[i]))
        {
            if((s[i]=='0'&&temp!=0)||(s[i]!='0'))
            temp++;
        }
        else if(temp!=0)
        {
            ans=ans<temp? temp:ans;
            temp=0;
        }
    }
    if(temp!=0)
    {
        ans=ans<temp? temp:ans;
        temp=0;
    }
    printf("%d",ans);
    return 0;
}
