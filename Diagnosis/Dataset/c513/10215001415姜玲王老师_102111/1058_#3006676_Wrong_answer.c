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
         int flag1=0,flag2=0;
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
            flag1++;
            b[j]=a[i];
            while(flag1%2||flag2%2)
            {i++;
            if(a[i]=='\'') flag1++;
            if(a[i]=='"') flag2++;
                b[j]=a[i];
            }
            continue;
        }
        if(a[i]=='"')
        {
            flag2++;
            b[j]=a[i];
            while(flag1%2||flag2%2)
            {i++;
            if(a[i]=='\'') flag1++;
            if(a[i]=='"') flag2++;
            b[j]=a[i];
            }
            continue;
        }
         b[j]=a[i];
         j++;

     }
     b[j]=0;
     printf("%s",b);
}
