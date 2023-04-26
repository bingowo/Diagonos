#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
     char a[10000],b[10000]={0};
     char c;
     int i=0,j=0;
     while((c=getchar())!=EOF)
     {
         a[i]=c;
         i++;
     }
     a[i]=0;
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
             i++;
             continue;
         }
         b[j]=a[i];
         j++;

     }
     
     printf("%s",b);
}
