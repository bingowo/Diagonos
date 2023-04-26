#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

int main()
{
   int i,j,len=0;
   char s[101];
   scanf("%s",s);
   for(i=0;i<strlen(s);i++){
        if(s[i-1]!='0' && isdigit(s[i])!=0 ){len++;}





   }

   printf("%d",len);




return 0;
}