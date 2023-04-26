#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];scanf("%s",s);
        char c;int len=strlen(s);int bo=1;
        for(int j=0;j<len;j++)
        {
            c=s[j];
            if(c=='(')
            {
                if(s[j+1]=='{'||s[j+1]==')') ;
                else {printf("No\n");bo=0;break;}
            }
            if(c=='{')
            {
                if(s[j+1]=='['||s[j+1]=='}') ;
                else {printf("No\n");bo=0;break;}
            }
            if(c=='[')
            {
                if(s[j+1]=='('||s[j+1]==']') ;
                else {printf("No\n");bo=0;break;}
            }
        }
        for(int j=len-1;j>0;j--)
        {
            c=s[j];
            if(c=='}')
            {
                if(s[j-1]==']'||s[j-1]=='{') ;
                else {printf("No\n");bo=0;break;}
            }
            if(c==']')
            {
                if(s[j-1]==')'||s[j-1]==')') ;
                else {printf("No\n");bo=0;break;}
            }
            if(c==')')
            {
                if(s[j-1]=='}'||s[j-1]=='(') ;
                else {printf("No\n");bo=0;break;}
            }
        }
        if(bo) printf("Yes\n");
    }
    return 0;
}
