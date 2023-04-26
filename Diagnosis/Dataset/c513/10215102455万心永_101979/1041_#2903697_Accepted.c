#include<stdio.h>
#include<string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int l=strlen(s),count=1,ans=1;
    char temp=s[0];
    for (int i=1;i<l;i++)
    {
        if (s[i]!=temp)
            count++;
        else if (s[i]==temp)
        {
            if (count>=ans)
            {
                ans=count;count=1;
            }
            else 
                count=1;
        }
        temp=s[i];
    }
    if (count>=ans) ans=count;
    printf("%d",ans);
}