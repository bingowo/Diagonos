#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
     char a[5000],b[5000];
     char c;
     int i=0,j;
     while((c=getchar())!=EOF)
     {
         a[i]=c;
         i++;
     }
     for(i=0;i<strlen(a);i++)
     {
         if(a[i]=='/'&&a[i+1]=='/')
         {
             while(a[i]!='\n')
             {
                 i++;
             }
         }
         if(a[i]=='/'&&a[i+1]=='*')
         {
             i+=2;
             while(!(a[i]=='*'&&a[i+1]=='/'))
             {
                 i++;
             }
             a[i]++;
             continue;
         }
         b[j]=a[i];
         j++;

     }
     printf("%s",b);
}
