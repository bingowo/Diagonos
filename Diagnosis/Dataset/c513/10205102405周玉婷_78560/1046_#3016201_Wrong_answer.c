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
           char c=s[i];
          ss[i] = tolower(c);
       }
       ss[i] = 0;
       
       if(strcmp(ss,"the")==0) continue;
       else if(strcmp(ss,"a")==0) continue;
       else if(strcmp(ss,"an")==0) continue;
       else if(strcmp(ss,"of")==0) continue;
       else if(strcmp(ss,"for")==0) continue;
       else if(strcmp(ss,"and")==0) continue;
       else num++;
       }
       printf("case #%d:\n",j);
       printf("%d\n",num);
    }
}