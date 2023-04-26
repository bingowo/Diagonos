#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char s[51];
   scanf("%s",s);
   int count=0;
   int temp=1;
   char ch=s[0];
   for(int i=1;i<strlen(s);i++)
   {
       if(s[i]!=ch)
       {
           temp++;
           ch=s[i];
       }
       else{
        if(temp>count)
        {
            count=temp;
        }
        temp=1;
       }
   }
   if(temp>count)
   {
       count=temp;
   }
   printf("%d\n",count);
   return 0;
}
