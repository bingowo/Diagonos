#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int ans[4]={0};
int main()
{
    char s[50];
    memset(s,0,sizeof(s));
    while(scanf("%s\n",s)!=EOF)
    {
        if(s[0]=='I')
        {
            if(s[2]=='A')
            {
                int a=0;
                for(int i=5;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[0]=a;
            }
            if(s[2]=='B')
            {
                int a=0;
                for(int i=5;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[1]=a;
            }
            if(s[2]=='C')
            {
                int a=0;
                for(int i=5;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[2]=a;
            }
            if(s[2]=='D')
            {
                int a=0;
                for(int i=5;i<strlen(s);i++)
                    a=a*10+s[i]-'0';
                ans[3]=a;
            }
        }
        if(s[0]=='M'&&s[1]=='O')
        {
            int m=s[3]-'A';
            int n=s[6]-'A';
            ans[m]=ans[n];
        }
        if(s[0]=='A')
        {
            int m=s[3]-'A';
            int n=s[6]-'A';
            ans[m]+=ans[n];
        }
        if(s[0]=='S')
        {
            int m=s[3]-'A';
            int n=s[6]-'A';
            ans[m]-=ans[n];
        }
        if(s[0]=='M'&&s[1]=='U')
        {
            int m=s[3]-'A';
            int n=s[6]-'A';
            ans[m]*=ans[n];
        }
        if(s[0]=='D')
        {
            int m=s[3]-'A';
            int n=s[6]-'A';
            ans[m]/=ans[n];
        }
        if(s[0]=='O')
        {
            int m=s[3]-'A';
            printf("%d\n",ans[m]);
        }
        memset(s,0,sizeof(s));
    }

}
