#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans[4]={0};
int main()
{
    char s1[50];
    while(scanf("%s",s1)!=EOF)
    {
        char s2[50];
        scanf("%s",s2);
        if(s1[0]=='I')
        {
            if(s2[0]=='A')
            {
                int a=0;
                int flag=1;
                if(s2[3]=='-')
                {
                    flag=-1;
                    for(int i=4;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                else
                {
                    for(int i=3;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                a*=flag;
                ans[0]=a;
            }
            if(s2[0]=='B')
            {
                int a=0;
                int flag=1;
                if(s2[3]=='-')
                {
                    flag=-1;
                    for(int i=4;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                else
                {
                    for(int i=3;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                a*=flag;
                ans[0]=a;
            }
            if(s2[0]=='C')
            {
                int a=0;
                int flag=1;
                if(s2[3]=='-')
                {
                    flag=-1;
                    for(int i=4;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                else
                {
                    for(int i=3;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                a*=flag;
                ans[0]=a;
            }
            if(s2[0]=='D')
            {
                int a=0;
                int flag=1;
                if(s2[3]=='-')
                {
                    flag=-1;
                    for(int i=4;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                else
                {
                    for(int i=3;i<strlen(s2);i++)
                    a=a*10+s2[i]-'0';
                }
                a*=flag;
                ans[0]=a;
            }
        }
        if(s1[0]=='M'&&s1[1]=='O')
        {
            int m=s2[0]-'A';
            int n=s2[3]-'A';
            ans[m]=ans[n];
        }
        if(s1[0]=='A')
        {
            int m=s2[0]-'A';
            int n=s2[3]-'A';
            ans[m]+=ans[n];
        }
        if(s1[0]=='S')
        {
            int m=s2[0]-'A';
            int n=s2[3]-'A';
            ans[m]-=ans[n];
        }
        if(s1[0]=='M'&&s1[1]=='U')
        {
            int m=s2[0]-'A';
            int n=s2[3]-'A';
            ans[m]*=ans[n];
        }
        if(s1[0]=='D')
        {
            int m=s2[0]-'A';
            int n=s2[3]-'A';
            ans[m]/=ans[n];
        }
        if(s1[0]=='O')
        {
            int m=s2[0]-'A';
            printf("%d\n",ans[m]);
        }
    }

}
