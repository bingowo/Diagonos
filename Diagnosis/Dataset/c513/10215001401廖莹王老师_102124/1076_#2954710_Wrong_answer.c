#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,h=0;
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
        char s[110];int i=0,cont=0;
    scanf("%s",s);
    for(i=0;s[i];i++)
    {
              if(s[i]=='{'){if(s[i+1]=='}' || s[i+1]=='[');else {cont=-1;break;}}
        else if(s[i]=='['){if(s[i+1]==']' || s[i+1]=='(');else {cont=-1;break;}}
        else if(s[i]=='('){if(s[i+1]==')' || s[i+1]=='{');else {cont=-1;break;}}
        else if(s[i]=='}'){if(s[i-1]==']' || s[i-1]=='{');else {cont=-1;break;}}
        else if(s[i]==']'){if(s[i-1]=='[' || s[i-1]==')');else {cont=-1;break;}}
        else if(s[i]==')'){if(s[i-1]=='(' || s[i-1]=='}');else {cont=-1;break;}}
    }
    if(cont==-1)printf("No\n");
    else printf("Yes\n");


    }
    return 0;
}
