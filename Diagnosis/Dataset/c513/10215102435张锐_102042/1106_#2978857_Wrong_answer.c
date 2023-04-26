#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mult(int *ans,int n)
{
    if(n==1) return 1;
    else
    {
        int next=0;int temp;
        for(int i=999;i>=0;i--)
        {
            temp=ans[i]*n+next;
            if(temp>=10) next=temp/10,ans[i]=temp%10;
            else next=0,ans[i]=temp;
        }
    }

    return;
}
int main()
{
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
    int ans[1000]={0};
    ans[999]=1;
    if(len==1) ;
    else
        for(int i=0;i<len;i++)
        {
            if(i==0&&s[i+1]!=s[i]) mult(ans,2);
            else if(i==0&&s[i+1]==s[i]) continue;
            else if(i==len-1&&s[i]!=s[i-1]) mult(ans,2);
            else if(i==len-1&&s[i]==s[i-1]) continue;
            else if(s[i]==s[i-1]&&s[i]==s[i+1]) continue;
            else if(s[i]==s[i-1]&&s[i]!=s[i+1]) mult(ans,2);
            else if(s[i]!=s[i-1]&&s[i]==s[i+1]) mult(ans,2);
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) mult(ans,3);
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1]) mult(ans,2);
        }
    int p;
    for(p=0;;p++)
    {
        if(ans[p]!=0) break;
    }
    for(int i=p;i<1000;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
