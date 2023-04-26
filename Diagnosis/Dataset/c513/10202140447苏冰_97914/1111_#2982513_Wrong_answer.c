#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char s[50];
    char a[50][50];
    char b[50][50];
    for(int i=0;i<41;i++)
    {
        for(int j=0;j<41;j++)
        {
            a[i][j]='.';b[i][j]='.';
        }
        a[i][41]='\n';b[i][41]='\n';
    }
    for(int i=0;i<41;i++)
    {
        a[20][i]='-';b[20][i]='-';
    }
    for(int i=0;i<41;i++)
    {
        a[i][20]='|';b[i][20]='|';
    }
    a[20][40]='>'; b[20][40]='>';
    a[0][20]='^';  b[0][20]='^';
    a[20][20]='+'; b[20][20]='+';
    while(scanf("%s",s)!=EOF)
    {
        int flag=1;
        int i=5;
        int ans=0;
        for(int x=0;x<=20;x++)
        {
            flag=1;ans=0;
            i=5;
            while(i<strlen(s))
            {
                if(s[i]=='+')
                {
                    flag=1;i++;
                }
                else if(s[i]=='-')
                {
                    flag=-1;i++;
                }
                int xi=0;
                while(isdigit(s[i]))
                {
                    xi=xi*10+(s[i]-'0');
                    i++;
                }
                xi*=flag;
                if(xi==0) xi=flag;
                if(s[i]=='x')
                {
                    i++;
                    if(s[i]=='^')
                    {
                        i++;
                        if(s[i]=='2') ans+=xi*x*x;
                        else if(s[i]=='3') ans+=xi*x*x*x;
                        i++;
                    }
                    else
                    {
                        ans=ans+xi*x;
                    }
                }
                else
                {
                    ans+=xi;
                }
            }
            if(ans>=-20 && ans<=20)
            {
                a[20-ans][x+20]='*';
            }
            else break;
        }
        for(int x=0;x>=-20;x--)
        {
            flag=1;ans=0;
            i=5;
            while(i<strlen(s))
            {
                if(s[i]=='+')
                {
                    flag=1;i++;
                }
                else if(s[i]=='-')
                {
                    flag=-1;i++;
                }
                int xi=0;
                while(isdigit(s[i]))
                {
                    xi=xi*10+(s[i]-'0');
                    i++;
                }
                xi*=flag;
                if(xi==0) xi=flag;
                if(s[i]=='x')
                {
                    i++;
                    if(s[i]=='^')
                    {
                        i++;
                        if(s[i]=='2') ans+=xi*x*x;
                        else if(s[i]=='3') ans+=xi*x*x*x;
                        i++;
                    }
                    else
                    {
                        ans=ans+xi*x;
                    }
                }
                else
                {
                    ans+=xi;
                }
            }
            if(ans>=-20 && ans<=20)
            {
                a[20-ans][x+20]='*';
            }
            else break;
        }
        for(int i=0;i<41;i++)
        {
            for(int j=0;j<=41;j++)
            {
                printf("%c",a[i][j]);
                if(a[i][j]=='*') a[i][j]=b[i][j];
            }
        }
        printf("\n");
    }
    return 0;
}
