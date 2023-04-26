#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100],ans[10];
    scanf("%s",s);
    int flag = 1,a = 0,b = 0,c = 0,n = 0,i;
    for(i = 0;i<strlen(s);i++)
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
                if(s[i+1]=='^') a = atoi(ans)*flag;
                else b = atoi(ans)*flag;
            }
        }
    }
    if(isdigit(s[strlen(s)-1])&&s[strlen(s)-2]!='^')
        c = flag*atoi(ans);
    int p,q,j;
    flag = 0;
    if(a!=0&&c!=0)
    {for(i=1;i<=abs(a);i++)
    {
        if(a%i!=0) continue;
        else{
            p = a/i;
            for(j = 1;j<=abs(c);j++)
            {
                if(c%j!=0) continue;
                else{
                    q = c/j;
                    if(i*q+j*p==b) {flag=1;break;}
                }
            }
            if(flag) break;
        }
    }
    if(flag) printf("%d %d %d %d",i,j,p,q);
    else printf("No Answer!\n");
    }
    else{
        printf("%d %d 1 0",a,b);
    }

    return 0;

}
