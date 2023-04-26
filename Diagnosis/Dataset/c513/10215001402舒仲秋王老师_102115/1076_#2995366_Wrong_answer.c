#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int out(char s[],int l)
{
    int t,i,flag;
    if(l==2&&s[0]=='('&&s[1]==')') t=1;
    else
    {
        if(s[0]=='('&&s[1]!=')'&&s[1]!='{') t=0;
        else if(s[0]=='('&&(s[1]==')'||s[1]=='{'))
        {
            char str[101];
            for(i=1;i<l;i++)
                if(s[i]==')'&&s[i+1]!='['&&s[i+1]!='{') flag=i;
            for(i=0;i<flag-1;i++) str[i]=s[i+1];
            for(i=flag-1;i<l-2;i++) str[i]=s[i+2];
            t=out(str,l-2);
        }
        else if(s[0]=='['&&s[1]!='(') t=0;
        else if(s[0]=='['&&s[1]=='(')
        {
            char str[101];
            for(i=1;i<l;i++)
                if(s[i]==']'&&s[i+1]!='('&&s[i+1]!='{') flag=i;
            for(i=0;i<flag-1;i++) str[i]=s[i+1];
            for(i=flag-1;i<l-2;i++) str[i]=s[i+2];
            t=out(str,l-2);
        }
        else if(s[0]=='{'&&s[1]!='(') t=0;
        else if(s[0]=='{'&&s[1]=='(')
        {
            char str[101];
            for(i=1;i<l;i++)
                if(s[i]=='}'&&s[i+1]!='['&&s[i+1]!='(') flag=i;
            for(i=0;i<flag-1;i++) str[i]=s[i+1];
            for(i=flag-1;i<l-2;i++) str[i]=s[i+2];
            t=out(str,l-2);
        }
    }
    return t;
}

int main()
{
    int N,i;
    char str[101][101];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%s",str[i]);
    for(i=0;i<N;i++)
    {
        int l=strlen(str[i]);
        if(out(str[i],l)==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
