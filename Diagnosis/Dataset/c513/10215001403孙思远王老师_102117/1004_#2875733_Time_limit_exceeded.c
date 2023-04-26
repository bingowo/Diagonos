#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int in=0;
    double dou=0.0;
    while(scanf("%s",s))
    {
        int len,i,flag=0,pot,p=1;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='.')
            {
                flag=1;
                pot=i;
                break;
            }
        }
        if(flag)
        {
            for(i=0;i<pot;i++)
                dou=dou*10+s[i]-'0';
            for(i=pot+1;i<len;i++)
                {dou=dou*10+s[i]-'0';
                 p*=10;}
            dou/=p;
        }
        else
        {
            for(i=0;i<len;i++)
                in=in*10+s[i]-'0';
        }
    }
    printf("%d%ld",in,dou);
    return 0;
}
