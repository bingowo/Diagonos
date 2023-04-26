#include<stdio.h>
#include<string.h>

int solve(char*word,char*ans)
{
    for(int i=0;i<(int)strlen(word);i++)
    {if(word[i]>=97 && word[i]<=122) word[i]-=32;}
    //全部转换成大写字母
    int l=0,l1=strlen(word);
    ans[l++]=word[0];
    for(int i=1;i<l1;i++)
    {
        if(word[i]>=ans[0])
        {
            for(int i=l-1;i>=0;i--) ans[i+1]=ans[i];
            ans[0]=word[i];l++;
        }
        else ans[l++]=word[i];
    }
    return l;
}

int main()
{
    char word[1001],ans[1001];
    scanf("%s",word);
    int l=solve(word,ans);
    for(int i=0;i<l;i++) printf("%c",ans[i]);

    return 0;
}