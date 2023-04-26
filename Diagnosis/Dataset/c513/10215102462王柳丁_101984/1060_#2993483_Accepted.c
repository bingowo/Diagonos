#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
   char a[101];
   scanf("%s",a);
   int cnt=0,res=0,i,sign0=1;
   for(i=0;i<strlen(a);i++)
   {
       if(isdigit(a[i]))
       {
           if(a[i]!='0'||sign0==0)
           {
               sign0=0;
               cnt++;
               if(res<cnt)res=cnt;
           }
           else {sign0=1;}
       }
       else {cnt=0;sign0=1;}
   }
   printf("%d\n",res);
    return 0;
}
