#include <stdio.h>
#include <string.h>
#include  <ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int j = 0; j < n; j++)
    {
       int num=0
       char s[30];
       while(~scanf("%s",s))
       {
       if(strcmp(s,"the")==0) num--;
       else if(strcmp(tolower(s),"a")==0) num--;
       else if(strcmp(tolower(s),"an")==0) num--;
       else if(strcmp(tolower(s),"of")==0) num--;
       else if(strcmp(tolower(s),"for")==0) num--;
       else if(strcmp(tolower(s),"and")==0) num--;
       else num++;
       }
       printf("case #%d:\n",j);
       printf("%d\n",num);
    }
    return 0;
}