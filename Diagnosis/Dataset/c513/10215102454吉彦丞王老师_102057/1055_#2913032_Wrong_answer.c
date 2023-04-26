#include<stdio.h>
#include<string.h>
int main()
{
    char s[100000];
    scanf("%s",&s);
    int l=strlen(s);
    int t=1;
    int max=1;
    int sign=0;
    for(int i=1;i<l;i++)
    {
        int m=i-sign;
        for(int j=sign;j<m;j++)
        {
            if(s[j]!=s[m])
            {
                t=t+1;
            }
            else
            {
                if(max<t)
                {
                    max=t;
                    sign=sign+t-1;
                }
                t=1;
                continue;
            }
        }
    }
    if(max<t)
    {
        max=t;
    }
    for(int k=sign;k<sign+max;k++)
    {
        printf("%c",s[k]);
    }
    return 0;
}