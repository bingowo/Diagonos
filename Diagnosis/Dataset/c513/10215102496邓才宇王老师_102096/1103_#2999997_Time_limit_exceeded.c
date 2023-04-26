#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans[4]={0};
int main()
{
    char s[50];
    memset(s,0,sizeof(s));
    while(gets(s)!=EOF)
    {
        if(s[0]=='I')
        {
            if(s[3]=='A')
            {
                int a=0;
                for(int i=6;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[0]=a;
            }
            if(s[3]=='B')
            {
                int a=0;
                for(int i=6;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[1]=a;
            }
            if(s[3]=='C')
            {
                int a=0;
                for(int i=6;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[2]=a;
            }
            if(s[3]=='D')
            {
                int a=0;
                for(int i=6;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[3]=a;
            }
        }
        if(s[0]=='M'&&s[1]=='O')
        {
            int m=s[4]-'A';
            int n=s[7]-'A';
            ans[m]=ans[n];
        }
        if(s[0]=='A')
        {
            int m=s[4]-'A';
            int n=s[7]-'A';
            ans[m]+=ans[n];
        }
        if(s[0]=='S')
        {
            int m=s[4]-'A';
            int n=s[7]-'A';
            ans[m]-=ans[n];
        }
        if(s[0]=='M'&&s[1]=='U')
        {
            int m=s[4]-'A';
            int n=s[7]-'A';
            ans[m]*=ans[n];
        }
        if(s[0]=='D')
        {
            int m=s[4]-'A';
            int n=s[7]-'A';
            ans[m]/=ans[n];
        }
        if(s[0]=='O')
        {
            int m=s[4]-'A';
            printf("%d\n",ans[m]);
        }
        memset(s,0,sizeof(s));
    }

}
