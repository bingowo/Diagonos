#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char s[1001];
   gets(s);
   char s1[1001];
   int i;
   for(i=0;s[i];i++)
    s1[i]=toupper(s[i]);
    s1[i]='\0';
    char ans[1001][1001];
    ans[0][0]=s1[0];
    ans[0][1]='\0';
    int j;
   for(j=1;s1[j];j++)
   {
       char a[1001];
       char a1[1001];
       char b[1001];
       b[0]=s1[j];
       b[1]='\0';
       strcpy(a,ans[j-1]);
       strcpy(a1,ans[j-1]);
        strcat(a,b);
        strcat(b,a1);
        if(strcmp(a,b)>0) strcpy(ans[j],a);
        else strcpy(ans[j],b);
   }
   printf("%s",ans[j-1]);
}
