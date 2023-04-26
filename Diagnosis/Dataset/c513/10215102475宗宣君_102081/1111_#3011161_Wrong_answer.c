#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100],ans[10];
    while(scanf("%s",s)!=EOF)
    {int flag = 1,a = 0,b = 0,c = 0,d = 0,n = 0,i;
    for(i = 5;i<strlen(s);i++)
    {
        if(s[i]=='+') flag = 1;
        else if(s[i]=='-') flag = -1;
        else if(isdigit(s[i])&&s[i-1]!='^')
        {
            ans[n++] = s[i];
        }
        else if(s[i]=='x')
        {
            if(!isdigit(s[i-1]))
            {
                if(s[i+1]=='^') a = 1*flag;
                else b = 1*flag;
            }
            else{
                ans[n] = '\0';
                n = 0;
                if(s[i+1]=='^')
                {if(s[i+2]=='3') a = atoi(ans)*flag;
                else b = atoi(ans)*flag;
                }
                else c = atoi(ans)*flag;
            }
        }
    }
    if(isdigit(s[strlen(s)-1])&&s[strlen(s)-2]!='^')
        ans[n] = '\0',d = flag*atoi(ans);
    char graph[41][41];
    int j,res;
    for(i = 0;i<41;i++)
        {for(j = 0;j<41;j++)
    {
        if(i==0&&j==20)graph[i][j] = '^';
        else if(i==20&&j!=20&&j!=40) graph[i][j] = '-';
        else if(i==20&&j==20) graph[i][j] = '+';
        else if(i==20&&j==40) graph[i][j] = '>';
        else if(j==20) graph[i][j] = '|';
        else graph[i][j] = '.';
    }
        }
    for(i = -20;i<=20;i++)
    {
        res = a*i*i*i+b*i*i+c*i+d;
        if(res>20||res<-20) continue;
        else graph[20-res][i+20] = '*';
    }
    for(i = 0;i<41;i++)
        {for(j = 0;j<41;j++)
        printf("%c",graph[i][j]);
        printf("\n");
        }
    printf("\n");
    }
    return 0;

}
