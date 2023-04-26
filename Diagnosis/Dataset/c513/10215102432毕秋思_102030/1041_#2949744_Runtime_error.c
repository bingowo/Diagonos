#include<stdio.h>

int main()
{
    char s[50];
    gets(s);
    int ans=1;
    int count=1;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]!=s[i+1]) count++;
        else
        {
            ans=count>ans?count:ans;
            count=1;
        }
    }
    ans=count>ans?count:ans;
    printf("%d",ans);
    return 0;
}
