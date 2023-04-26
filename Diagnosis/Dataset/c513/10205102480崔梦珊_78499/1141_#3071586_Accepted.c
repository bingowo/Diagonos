#include<stdio.h>
#include<string.h>
long long f(char* s)
{
    long long ans=0;
    int len=strlen(s);
    int level=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            level++;
            i++;
            while(level!=0)
            {
                if(s[i]=='(')
                {
                    level++;
                }
                else
                {
                    if(s[i-1]=='(')
                    {
                        level--;
                        ans=ans+pow(2,level);
                    }
                    if(s[i-1]==')')
                    {
                        level--;
                    }
                }
                i++;
            }
            i--;
        }
    }
    return ans;
}

int main()
{
    char s[60];
    scanf("%s",s);
    printf("%lld",f(s));
}
