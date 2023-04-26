#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];char c;int ii=0;
        while((c=getchar)!='\n')
        {
            if(c=='(') s[ii++]=c;
            else if(c=='{') s[ii++]=c;
            else if(c=='[') s[ii++]=c;
            else if(c==')')
            {
                if(s[ii-1]=='(') ii--;
                else s[ii++]=c;
            }
            else if(c=='}')
            {
                if(s[ii-1]=='{') ii--;
                else s[ii++]=c;
            }
            else if(c==']')
            {
                if(s[ii-1]=='[') ii--;
                else s[ii++]=c;
            }
        }
        if(ii==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
