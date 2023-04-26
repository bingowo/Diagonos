#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    char s[105];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int l=strlen(s);

        int flag=0;
        for(int j=0;(j<l-1)&&(flag==0);j++)
        {
           if((s[j]=='{')&&(s[j+1]!='['))flag=1;
           if((s[j]=='[')&&(s[j+1]!='('))flag=1;
           if(s[j]=='(')
           {
               if((s[j+1]!=')')&&(s[j+1]!='{'))flag=1;
           }
        }
        if(flag==0)printf("Yes\n");
        else printf("No\n");


    }




}
