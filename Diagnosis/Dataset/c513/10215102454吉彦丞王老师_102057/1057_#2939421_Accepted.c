#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    scanf("%s",&s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-32;
        }
    }
    char c[2000];
    c[1000]=s[0];
    char max=s[0];
    char min=s[0];
    int start=1000;
    int end=1000;
    for(int i=1;i<l;i++)
    {
        if(s[i]>=max)
        {
            max=s[i];
            start--;
            c[start]=s[i];
        }
        else
        {
            if(s[i]<=min)
            {
                min=s[i];
            }
            end++;
            c[end]=s[i];
        }
    }
    for(int j=start;j<end+1;j++)
    {
        printf("%c",c[j]);
    }
    return 0;
}