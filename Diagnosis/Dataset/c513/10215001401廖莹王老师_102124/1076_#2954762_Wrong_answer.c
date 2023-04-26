#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,h=0;
    
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
        int p[6]={0};
        char s[110];int i=0,cont=0;
    scanf("%s",s);
    for(i=0;s[i];i++)
    {
              if(s[i]=='{'){p[0]++;if(s[i+1]=='}' || s[i+1]=='[');else {cont=-1;break;}}
        else if(s[i]=='['){p[1]++;if(s[i+1]==']' || s[i+1]=='(');else {cont=-1;break;}}
        else if(s[i]=='('){p[2]++;if(s[i+1]==')' || s[i+1]=='{');else {cont=-1;break;}}
        else if(s[i]=='}'){p[3]--;if(s[i-1]==']' || s[i-1]=='{');else {cont=-1;break;}}
        else if(s[i]==']'){p[4]--;if(s[i-1]=='[' || s[i-1]==')');else {cont=-1;break;}}
        else if(s[i]==')'){p[5]--;if(s[i-1]=='(' || s[i-1]=='}');else {cont=-1;break;}}
    }
    if(cont==-1)printf("No\n");
    else
    {
        int k=p[0]+p[1]+p[2]+p[3]+p[4]+p[5];
        if(k!=0)printf("No\n");
        else printf("Yes\n");
    }



    }
    return 0;
}
