#include <stdio.h>
 int main()
 {
     char s[52];
     scanf("%s",s);
     char *p1=s,*p2=s+1;
     int count=1,max=1;
     while(*p2!=0)
     {
         if(*p1 !=*p2)  count++;
         else
         {
           if(max < count) max=count;
           count=1;
         }
         p1++;p2++;
     }
     if(max < count) max=count;
     printf("%d",max);
 }
 