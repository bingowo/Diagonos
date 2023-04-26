#include<stdio.h>
#include<string.h>

int judge(char*s)
{
    int l=strlen(s),flag=1;
    for(int i=0;i<l;i++)
    {
        switch (s[i])
        {
            case '{':
                if(s[i+1]=='[' || s[i+1]=='}') {flag*=4;break;}
                else return -1;
            case '}':
                if(s[i+1]=='{' || s[i+1]==')' || i==l-1) {flag/=4;break;}
                else if(flag==4) {flag/=4;break;}
                else return -1;
            case '[':
                if(s[i+1]=='(' || s[i+1]==']') {flag*=3;break;}
                else return -1;
            case ']':
                if(s[i+1]=='[' || s[i+1]=='}' || i==l-1) {flag/=3;break;}
                else if(flag==3) {flag/=3;break;}
                else return -1;
            case '(':
                if(s[i+1]=='{' || s[i+1]==')') {flag*=2;break;}
                else return -1;
            case ')':
                if(s[i+1]=='(' || s[i+1]==']' || i==l-1) {flag/=2;break;}
                else if(flag==2) {flag/=2;break;}
                else return -1;       
            default:break;
        }
    }
    if(flag==1) return 1;
    else return 0;
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[101];scanf("%s",s);
        if(judge(s)==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}