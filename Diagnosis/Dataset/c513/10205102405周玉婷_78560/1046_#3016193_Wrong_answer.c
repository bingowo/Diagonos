#include <stdio.h>
#include <string.h>
#include  <ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int j = 0; j < n; j++)
    {
       int num=0;
       char s[30],ss[30];
       while(~scanf("%s",s))
       {
        int i=0;
        for( i=0; s[i]!=0;i++)
       {
          ss[i] = tolower(s[i]);
       }
       ss[i] = 0;
       
       if(strcmp(ss,"the")==0) num--;
       else if(strcmp(ss,"a")==0) num--;
       else if(strcmp(ss,"an")==0) num--;
       else if(strcmp(ss,"of")==0) num--;
       else if(strcmp(ss,"for")==0) num--;
       else if(strcmp(ss,"and")==0) num--;
       else num++;
       }
       printf("case #%d:\n",j);
       printf("%d\n",num);
    }
    return 0;
}