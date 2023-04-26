#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
     char a[10000],b[10000];
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
        if(a[i]=='\'')
        {
           for(int t=0;t<=3;t++)
           {
               b[j]=a[i+t];
               j++;
           }
           i+=3;
            continue;
        }
        if(a[i]=='"')
        {
        int k=i+1;
        int t=i;
        for(;a[k]!='\n';k++)
           {
               if(a[k]=='"') t=k;
           }
           t++;
           for(;i<t;i++)
           {
                b[j]=a[i];
               j++;

           }
           i--;
           continue;

        }
         b[j]=a[i];
         j++;

     }
     b[j]=0;
     printf("%s",b);
}
