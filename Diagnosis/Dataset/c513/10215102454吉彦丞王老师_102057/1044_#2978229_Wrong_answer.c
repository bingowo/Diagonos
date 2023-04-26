#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    scanf("%s",&s);
    int l=strlen(s);
    int t=0;
    for(int i=0;i<l;i++)
    {
        int n=0;
        if(s[i]=='0'&&s[i+1]=='x')
        {
            t++;
            int m=i+2;
            for(int j=m;j<l;j++)
            {
                if(s[j]-'0'<10)
                {
                    n=(n+(s[j]-'0'))*16;
                }
                else if(s[j]-'0'>=49&&s[j]-'0'<=54)
                {
                    n=(n+(s[j]-'0')-39)*16;
                }
                else
                {
                    break;
                }
            }
            printf("%d ",n/16);
            n=0;
        }
        else
        {
            continue;
        }
    }
    if(t==0)
    {
        printf("-1");
    }
    return 0;
}