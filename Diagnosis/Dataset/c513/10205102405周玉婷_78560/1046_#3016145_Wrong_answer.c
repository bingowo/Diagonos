#include <stdio.h>
#include <string.h>
#include  <ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    int num=0;
    for(int j = 0; j < n; j++)
    {
       char s[30];
       while(~scanf("%s",s))
       {
       if(strcmp(s,"the")==0) num--;
       else if(strcmp(s,"a")==0) num--;
       else if(strcmp(s,"an")==0) num--;
       else if(strcmp(s,"of")==0) num--;
       else if(strcmp(s,"for")==0) num--;
       else if(strcmp(s,"and")==0) num--;
       else num++;
       }
       printf("case #%d:\n",j);
       printf("%d\n",num);
    }
}