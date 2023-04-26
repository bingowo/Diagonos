#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    int i,res = 1;
    for(i = 0;i<strlen(s);i++)
    {
        if(i==0)
        {
            if(i+1<strlen(s)&&s[i]!=s[i+1]) res*=2;
        }
        else if(i==strlen(s)-1)
        {if(s[i-1]!=s[i]) res *= 2;}
        else
        {
            if(s[i-1]!=s[i]&&s[i]!=s[i+1]) res *= 3;
            else if((s[i-1]==s[i]&&s[i]!=s[i+1])||(s[i-1]!=s[i]&&s[i]==s[i+1])) res*=2;
        }
    }
    printf("%d",res);
    return 0;
}
